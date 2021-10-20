#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for card number
    long int cardNumber;
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    // Check legitimacy
    int tempSum1 = 0, tempSum2 = 0;     // temporary variables will store the sum of parts of the number
    int numberLength = 0;               // counter, check number length
    int firstDig;                       // stores the first digit
    int firstTwo;                       // stores the first two digits
    int lastDigit;                      // stores the last digit at that point in time
    bool switcher = true;

    while (cardNumber > 0)
    {
        // Save the first digit
        if (cardNumber / 10 == 0)
        {
            firstDig = cardNumber;
        }
        
        // Save first two digits
        if ((cardNumber / 100 == 0) && (cardNumber / 10 != 0))
        {
            firstTwo = cardNumber;
        }

        // Sum digits of the card following Luhn’s Algorithm
        lastDigit = cardNumber % 10;
        if (switcher)
        {
            tempSum1 += lastDigit;
            cardNumber /= 10;
            switcher = false;
        }
        else
        {
            int lastDigitTimesTwo = lastDigit * 2;
            if (lastDigitTimesTwo > 9)                      // We want to add each digit individually for the checksum
            {
                tempSum2 += lastDigitTimesTwo % 10;
                tempSum2 += lastDigitTimesTwo / 10;
            }
            else
            {
                tempSum2 += lastDigitTimesTwo;
            }
            cardNumber /= 10;
            switcher = true;
        }
        numberLength++;                                     // Count the number of digits of the card
    }

    bool legit = false;
    if (((tempSum1 + tempSum2) % 10) == 0)
    {
        legit = true;
    }

    // Print results
    if (legit && (numberLength == 15) && (firstTwo == 34 || firstTwo == 37))
    {
        printf("AMEX\n");
    }
    else if (legit && (numberLength == 16) && (firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (legit && (numberLength == 13 || numberLength == 16) && firstDig == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
