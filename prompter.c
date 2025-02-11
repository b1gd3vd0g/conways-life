#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPositiveIntegerFeedback(int maximum)
{
    // reserve space in the stack for a 100 character string.
    char input[100];
    // loop until we happen to get an acceptable number.
    while (1)
    {
        // scan for user input.
        scanf("%[^\n]", input);
        // to avoid strange infinite loops regarding user feedback.
        while (getchar() != '\n')
            continue;

        int choice = atoi(input);
        if (choice == 0 && strcmp(input, "0") != 0)
        {
            // the input could not be parsed into an integer.
            printf("input \"%s\" could not be parsed to an integer.", input);
        }
        else if (choice < 1 || choice > maximum)
        {
            // the input was parsed to an invalid number.
            printf("input \"%d\" is not a valid option.", choice);
        }
        else
        {
            return choice;
        }
        // finish printing the try again prompt.
        printf(" Please try again.\n");
    }
}

int promptUserForNumericallyLabelledOption(char *prompt, int optionsCount, char **options)
{
    // print the prompt.
    printf("%s\n", prompt);
    for (int i = 0; i < optionsCount; i++)
    {
        // print each option.
        printf("%d) %s\n", i + 1, options[i]);
    }
    int choice = getPositiveIntegerFeedback(optionsCount);
    return choice;
}

int promptUserForPositiveInteger(char *prompt, int maximum)
{
    printf("%s\n", prompt);
    getPositiveIntegerFeedback(maximum);
}