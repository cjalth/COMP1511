// Message Cipher
// message_cipher.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 20/06/2023
//
// This program enciphers or deciphers a 4 letter long message using 
// 4 inputted numbers which is added to each letter. 

#include <stdio.h>

char encipher(char letter, int number) {
    if (number > 25 || number < -25) {
        number = number % 26; 
    }
    char newletter = letter + number;
    if (letter + number == 70) {
        newletter = newletter + 0;    
    }
    else if (letter + number > 122 || (letter < '[' && letter + number < 90)) {
        newletter = newletter - 26;
    }
    else if (letter + number < 65 || (letter > '`' && letter + number < 97)) {
        newletter = newletter + 26;
    }

    return newletter;
}

char decipher(char dletter, int dnumber) {
    if (dnumber > 25 || dnumber < -25) {
        dnumber = dnumber % 26; 
    }
    char dnewletter = dletter - dnumber;
    if (dletter - dnumber == 87) {
        dnewletter = dnewletter + 0;    
    }
    else if (dletter - dnumber == 76){
        dnewletter = dnewletter + 0;
    }
    else if (dletter - dnumber == 67){
        dnewletter = dnewletter + 0;
    }
    else if (dletter - dnumber > 122 || (dletter < '[' && dletter - dnumber < 90)) {
        dnewletter = dnewletter - 26;
    }
    else if (dletter - dnumber < 65 || (dletter > '`' && dletter - dnumber < 97)) {
        dnewletter = dnewletter + 26;
    }

    return dnewletter;
}


// This main function scans a message then enciphers it by some given inputs
int main(void) {
    // Have a think about how we might implement this with a `struct message`
    // once we've covered structs in the Thursday lecture!
    char letter1;
    char letter2;
    char letter3;
    char letter4;
    int number1;
    int number2;
    int number3; 
    int number4;
    char cipher;

    // Scan message into the four characters
    printf("Message: ");
    scanf(
        "%c %c %c %c",
        &letter1, &letter2, &letter3, &letter4
    );

    printf("Would you like to encipher or decipher this message (e/d)? ");
    scanf(" %c", &cipher);

    if(cipher == 'e') {
        printf("Enter numbers to encipher by: ");
        scanf("%d %d %d %d", 
        &number1, &number2, &number3, &number4);
        letter1 = encipher(letter1, number1);
        letter2 = encipher(letter2, number2);
        letter3 = encipher(letter3, number3);
        letter4 = encipher(letter4, number4);
    }
    else if (cipher == 'd') {
        printf("Enter numbers to decipher by: ");
        scanf("%d %d %d %d", 
        &number1, &number2, &number3, &number4);
        letter1 = decipher(letter1, number1);
        letter2 = decipher(letter2, number2);
        letter3 = decipher(letter3, number3);
        letter4 = decipher(letter4, number4);
    }

    printf("%c%c%c%c\n", letter1, letter2, letter3, letter4);

    return 0;
}
