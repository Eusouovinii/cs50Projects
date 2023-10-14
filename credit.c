
/*
    Filename:                       Template.c
    Dependencies:                   Look at the include.
    Author:                         Vinicius Baradel.
    github:                         https://github.com/Eusouovinii .
    Date :                          14/10/2023.
    Software License Agreemente:    For educational purposes only.

    File description: Checks whether a credit card is valid and whether it is AMEX, VISA or MASTERCARD.

    Change History
    1.0 14/10/2033 First Version
*/

#include <cs50.h>
#include <stdio.h>

// Pre-declaration of the functions.
int prim(long number);
int segu(long number);
int terc(long number);
int quar(long number);
int quin(long number);
int sext(long number);
int seti(long number);
int oita(long number);
int nono(long number);
int deci(long number);
int dec1(long number);
int dec2(long number);
int dec3(long number);
int dec4(long number);
int dec5(long number);
int dec6(long number);
int separaDois(long number);
int dobro(long number);
int somaUm(long number);
int somaDois(long number);
bool isvalid(long number);
int typeCard(long number);

int main(void)
{
    // Ask input for the user.
    long credit= get_long("Number: ");
    // Output the type of the card or if it is invalid.
    if (isvalid(credit))
    {
        switch(typeCard(credit))
        {
            case 1:
            printf("AMEX\n");
            break;

            case 2:
            printf("VISA\n");
            break;

            case 3:
            printf("MASTERCARD\n");
            break;

            case 4:
            printf("INVALID\n");
            break;
        }

    }
    else
    {
        printf("INVALID\n");
    }

}

// Calculates the first digit of a number

int prim(long number)
{
    long prim = number%10;
    return prim;
}

// Calculates the second digit of a number.

int segu(long number)
{
    long segu = ((number%100) - prim(number) ) /10;
    return segu;
}

// Calculates the third digit of a number.

int terc(long number)
{
    long terc = ((number%1000) - segu(number))/100;
    return terc;
}

// Calculates the fourth digit of a number.

int quar(long number)
{
    long quar = ((number%10000) - terc(number))/1000;
    return quar;
}

// Calculates the fifth digit of a number.

int quin(long number)
{
   long quinto = ((number%100000)-quar(number))/10000;
   return quinto ;
}

// Calculates the sixth digit of a number.

int sext(long number)
{
    long sexto =((number%1000000)-quin(number))/100000;
    return sexto;
}

// Calculates the seventh digit of a number.

int seti(long number)
{
    long setimo = ((number%10000000)-sext(number))/1000000;
    return setimo;
}

// Calculates the eighth digit of a number.

int oita(long number)
{
     long oitavo = ((number%100000000)-seti(number))/10000000;
     return oitavo;
}

// Calculates the ninth digit of a number.

int nono(long number)
{
    long nono = ((number%1000000000)-oita(number))/100000000;
    return nono;
}

// Calculates the tenth digit of a number.

int deci(long number)
{
    long decimo = ((number%10000000000)-nono(number))/1000000000;
    return decimo;
}

// Calculates the eleventh digit of a number.

int dec1(long number)
{
    long dec1 = ((number%100000000000)-deci(number))/10000000000;
    return dec1;
}

// Calculates the twelfth digit of a number.

int dec2(long number)
{
    long dec2 = ((number%1000000000000)-dec1(number))/100000000000;
    return dec2;
}

// Calculates the thirteenth digit of a number.

int dec3(long number)
{
    long dec3 = ((number%10000000000000)-dec2(number))/1000000000000;
    return dec3;
}

// Calculates the fourteenth digit of a number.

int dec4(long number)
{
    long dec4 = ((number%100000000000000)-dec3(number))/10000000000000;
    return dec4;
}

// Calculates the fifteenth digit of a number.

int dec5(long number)
{
    long dec5 = ((number%1000000000000000)-dec4(number))/100000000000000;
    return dec5;
}

// Calculates the sixteenth digit of a number.

int dec6(long number)
{
    long dec6 = ((number%10000000000000000)-dec5(number))/1000000000000000;
    return dec6;
}

// The next 5 functions refer to the use of the Luhn's algorithm.
// Calculates twice a number.

int dobro(long number)
{
    long dobrado = number * 2;
    return dobrado;
}

// Takes the first and second digits of a number and adds them together.

int separaDois(long number)
{
    long separaD = segu(dobro(number)) + prim(dobro(number));
    return separaD;

}

// Add together the 2 first digits of every digit of a number starting from the second-to-last digit.

int somaUm(long number)
{
    long soma1 = separaDois(dec6(number)) + separaDois(dec4(number)) + separaDois(dec2(number)) + separaDois(deci(number))
    + separaDois(oita(number)) + separaDois(sext(number)) + separaDois(quar(number)) + separaDois(segu(number));
    return soma1;
}

// Add together the rest of the numbers.

int somaDois(long number)
{
    long soma2 = somaUm(number) + dec5(number) + dec3(number) + dec1(number) + nono(number) + seti(number) + quin(number)
    + terc(number) + prim(number);
    return soma2;
}

// Check if a credit card is valid.

bool isvalid(long number)
{
    bool valid = false;
    if ((somaDois(number)) % 10 == 0)
    {
        return valid =true;
    }
    else
    {
        return valid = false;
    }
}

// Check the type of card (AMEX, VISA or MASTERCARD).

int typeCard(long number)
{
    int type = 0;
    if (dec6(number) == 0)
    {
        if (dec5(number) == 3 && ((dec4(number)== 4) || dec4(number) == 7))
        {
            return type = 1;
        }
        else if (dec5(number) == 0 && dec4(number) == 0 && dec3(number) == 4)
        {
            return type = 2;
        }
        else
        {
            return type = 4;
        }
        return type;
    }
    else if (dec6(number) == 4)
    {
        return type = 2;
    }
    else if (dec6(number) == 5 && (dec5(number) == 1 || dec5(number) == 2 ||  dec5(number) == 3 || dec5(number) == 4 ||
    dec5(number) == 5 ))
    {
        return type = 3;
    }
    else
    {
        return type = 4;
    }
    return type;
}


