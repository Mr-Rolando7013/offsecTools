#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// TODO : Look for common LDAP queries

int main(){
	int SIZE = 1000;
	char input[SIZE];
	string newUsers[30];
	
	fstream file;
	file.open("outputUsers.txt", ios::in);
	
	if (file.fail()){
		cout << "File not opened!" << endl;
	}
	int c = 0;
	while(!file.eof()){
		file.getline(input, SIZE);
		
		char* token = strtok(input, " ");
			int i = 0;
			while (token != NULL) {
				if (i == 7){
					newUsers[c] = token;
				}
				
				token = strtok(NULL, " ");
				i++;
			}
			c++;
	}
	
	int userSize = sizeof(newUsers) / sizeof(newUsers[0]);
	
	for (int i = 0; i < userSize; i++){
		cout << newUsers[i] << endl;
	}
	
	
	
	return 0;
}