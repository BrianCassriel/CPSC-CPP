//
//  main.cpp
//  Sealed Authenticator Stystem
//
//  Created by Brian Cassriel on 2/22/23.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    char charOne = 'E';
    char charTwo = 'C';
    char charThree = 'A';
    char userCharOne;
    char userCharTwo;
    char userCharThree;
    string authCode = "";
    string userCode = "";
    bool isMessageValid = true;
    int isValidCodeChecksum = 5;
    int checksum;
    
    cout << "Enter the first character of the message code: ";
    cin >> userCharOne;
    cout << "Enter the first character of the message code: ";
    cin >> userCharTwo;
    cout << "Enter the first character of the message code: ";
    cin >> userCharThree;
    
    authCode += charOne;
    authCode += charTwo;
    authCode += charThree;
    userCode += userCharOne;
    userCode += userCharTwo;
    userCode += userCharThree;
    cout << "Authenticator Code: " << authCode << endl;
    cout << "Message Code: " << userCode << endl << endl;
    
    if (charOne != userCharOne || charTwo != userCharTwo || charThree != userCharThree)
        isMessageValid = false;
    if (isMessageValid)
        cout << "Message is authentic" << endl;
    else
        cout << "Message is invalid" << endl;
    
    if (authCode != userCode)
        cout << "Concurrence: message is invalid" << endl << endl;
    else
        cout << "Concurrence: message is authentic" << endl << endl;
    
    
    cout << "Characterization of Message Code\n--------------------------------" << endl;
    
    cout << "ASCII Values of Message Code Characters: " << int(userCharOne) << ", " << int(userCharTwo) << ", " << int(userCharThree) << endl;
    cout << "Sum of ASCII Values for Message Code Characters: " << int(userCharOne) + int(userCharTwo) + int(userCharThree) << endl;
    
    checksum = (int(userCharOne) + int(userCharTwo) + int(userCharThree)) % 7;
    if (checksum == isValidCodeChecksum)
        cout << "Message code checksum is valid: " << checksum << endl;
    else
        cout << "Message code checksum is invalid: " << checksum << "; expected: " << isValidCodeChecksum << endl;
    
    if (userCharOne != charOne)
        cout << "First characters do not match: Message: " << userCharOne << "; Authenticator: " << charOne << endl;
    if (userCharTwo != charTwo)
        cout << "Second characters do not match: Message: " << userCharTwo << "; Authenticator: " << charTwo << endl;
    if (userCharThree != charThree)
        cout << "Third characters do not match: Message: " << userCharThree << "; Authenticator: " << charThree << endl;
    
    if (userCode < authCode)
        cout << "Message code (" << userCode << ") is lexicographically less than Authenticator code (" << authCode << ")" << endl;
    if (userCode > authCode)
        cout << "Message code (" << userCode << ") is lexicographically greater than than Authenticator code (" << authCode << ")" << endl;
    
    return 0;
}
