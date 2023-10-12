//Telephone-Number Word Generator) Standard telephone keypads contain the digits 0–9. The numbers 2–9 each have three letters associated with them, as is indicated by the following table:
// Digit Letter 	Digit Letter
// 2 	A B C 	6 	  M N O
// 3 	D E F 	7 	  P R S
// 4 	G H I 	8 	  T U V
// 5 	J K L 	9 	  W X Y

#include <stdio.h>
#include <stdbool.h>

// function prototypes
void generateNumberCombonation(FILE *cftpr, char *word, const char *phoneNumber, int currentNumber);
// array that holds all of the individual letters. This must be declared outside the scope of the main method in order to be accessed. This makes it declared globally.
const char *letterCombination[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

int main(void)
{
    // declaring the file for reference. This was taken from the assigned reading.
    FILE *cfPtr;
    char phoneNumber[8];
    char word[8];

    // fopen opens file. Exit program if unable to create file
    if ((cfPtr = fopen("/home/tyler/C_Assignments_11.13.txt", "w")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        while (true)
        {
            // instructions to the user to see the letter combination array.
            puts("Enter a seven digit phone number (not including 0 or 1) to see every seven letter combination.");
            scanf("%7s", phoneNumber);
            bool isValid = true;

            for (int i = 0; i < 7; i++)
            {

                if (phoneNumber[i] == '0' || phoneNumber[i] == '1')
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                // call to the declared function. Starting at zero in the array
                generateNumberCombonation(cfPtr, word, phoneNumber, 0);
                // fclose closes file
                fclose(cfPtr);
                return 0;
            }
            else
            {
                printf("Invalid phone number. Do not use '1' or '0'. Try again \n");
            }
        }
    }
}

void generateNumberCombonation(FILE *cfPtr, char *word, const char *phoneNumber, int currentNumber)
{
    // checks to ensure the array of numbers inputted is equal to 7. If this is true, we enter the recursive function and print the word array to the file.
    if (currentNumber == 7)
    {
        fprintf(cfPtr, "%.7s\n", word);
        return;
    }
    // here we identify the current number being iterated from the phone number array and assign it to the specific number. We then set letter to the global array letterCombination. The specific number is taken as the corresponding letterCombination array. We subtract 2 in order to correspond to the correct array index.
    int specificNumber = phoneNumber[currentNumber] - '2';
    const char *letter = letterCombination[specificNumber];
    // looping through the letter combinations in the letter array, and places a letter in the word array as the current number.
    for (int i = 0; letter[i] != '\0'; i++)
    {
        word[currentNumber] = letter[i];
        // recursive call to the function incrimenting by 1. This allows us to iterate through every possibility.
        generateNumberCombonation(cfPtr, word, phoneNumber, currentNumber + 1);
    }
}