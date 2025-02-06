// Message Encipher
// message_encipher.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 15/06/2023
//
// This program enciphers a 4 letter long message using 4 inputted numbers
// which is added to each letter. 

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

    // Scan message into the four characters
    printf("Message: ");
    scanf(
        "%c %c %c %c",
        &letter1, &letter2, &letter3, &letter4
    );

    printf("Enter numbers to encipher by: ");
    scanf("%d %d %d %d", 
            &number1, &number2, &number3, &number4);

    letter1 = encipher(letter1, number1);
    letter2 = encipher(letter2, number2);
    letter3 = encipher(letter3, number3);
    letter4 = encipher(letter4, number4);

    printf("%c%c%c%c\n", letter1, letter2, letter3, letter4);

    return 0;
}

