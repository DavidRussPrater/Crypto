// Author: David Prater


#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string readFile(string);
char encryptChar(char);
char decryptChar(char);
string encryptMessage(string);
string decryptMessage(string);
void writeToFile(string);

int main(int argc, char* argv[]){

	//Declare variables
	string message, fileName;
	string cryptChoice = (argv[1]);
	string stringKey = argv[2];
	fileName = (argv[3]);
	int key;
	istringstream (stringKey) >> key;
	message = readFile(fileName);
	string newMessage;
	
	// Employ functions to encrypt the message
	if (cryptChoice == "-e"){
		cout << "Encrypting file: " << fileName << endl;
		cout << message << endl;
		cout << encryptMessage(message) << endl;
		writeToFile(encryptMessage(message));}
	
	// Employ functions to decrypt the message
	if (cryptChoice == "-d"){
		cout << "Decrypting file: " << fileName << endl;
		cout << message << endl;
		cout << decryptMessage(message) << endl;
		writeToFile(decryptMessage(message));}
		
	
	return 0;
}

// Function to read data in from file
string readFile(string theFile){
	ifstream messageFile;
	string message;
	messageFile.open(theFile);
	getline(messageFile, message);
	return message;
}

// Funciton that sets offset of shift
 char encryptChar(char b, int key){
	char a = b;
	a+=key;
	return a;
}

// Funciton that sets opposite of shift
char decryptChar(char b, int key){
	char a = b;
	a-=key;
	return a;
}

// Function to change each charcter of the input file by the offset
string encryptMessage(string message){
	
	int a = 0;
	char temp;
	string messageEncrypted;
	do {
		temp = encryptChar(message[a]);
		messageEncrypted[a] = temp;
		message[a] = messageEncrypted[a];
		a+=1;
	} while (message[a] != '\0');
	
return message;
}

// Function to change each charcter of the input file by the opposite of the offset
string decryptMessage(string message){
	
	int a = 0;
	char temp;
	string messageDecrypted;
	do {
		temp = decryptChar(message[a]);
		messageDecrypted[a] = temp;
		message[a] = messageDecrypted[a];
		a+=1;
	} while (message[a] != '\0');
	
return message;
}

// Function to write new message to file
void writeToFile(string message){
	fstream printFile;
	printFile.open("message.txt");
	printFile << message << "\n";
	printFile.close();
}
