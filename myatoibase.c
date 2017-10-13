#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/**
 * Fabien DUBOIS
 * C++ TP 27/09/2017
 * */
// COMPILATION : gcc -W main.c fonctionsSudoku.c -o prog
int myatoibase(const char *nptr, const int base)
{
    // int nbChar = 0;
    unsigned char charActu = 0;
    int resultat = 0;
    int signe = 1;
    
    // VERIFICATION BASE ENTRE 0 et 10 
    if(base < 0 && base > 10)
    {
        return (0);       
    }

    // SIGNE : POSITIF / NEGATIF
    if (nptr[charActu] == '-')
    {
        signe = -1;
        charActu++;
    } 

    // PARCOUR CHAINE CARACTERE, VERIFICATION CHARACTER, TRANSFORMATION BASE 10
    while(nptr[charActu] != '\0')
    {
        if (nptr[charActu] >= '0' && nptr[charActu] <= '9')
        {    
            if(resultat * 10 < resultat)     
            {
                printf("\nOverflow\n");
                return (0);
            }     
            resultat = resultat*10 + nptr[charActu] - '0';
            if(resultat < 0 )
            {
                printf("\nOverflow\n");
                return (0);  
            }
        }
        else
        {
            printf("\nCode - Erreur 0\n");
            return (0); 
        }
        charActu++;
    }
    
    // BASE 2 à 9
    if(base >= 2 && base <=9)
    {
        int reste; 
        int n = resultat;
        int binary = 0, i = 1;
         
        while(n != 0) 
        {
            reste = n%base;
            n = n/base;
            binary = binary + (reste*i);
            i = i*10;
            if(binary < 0)
            {
                printf("\nOverflow\n");
                return (42);  
            }
        }
           resultat = binary;
    }

    // BASE 1
    if(base == 1)
    {
        int i = 1;
        int base1 = 1;
        
        while(i<resultat)
        {
           base1 = base1*10 + 1;
           if(base1 < 0)
           {
               printf("\nOverflow\n");
               return (42);  
           }
           i++;         
        }
        resultat = base1;
    }
    return signe*resultat;
}

int main() {
    int val;
    char str[32];
    strcpy(str, "42");
    val = myatoibase(str, 10);
    printf("Str = %s,Int = %d\n", str, val);
    strcpy(str, "100");
    val = myatoibase(str, 2); //1100100 printf("Str = %s,Int = %d\n", str, val);
    strcpy(str, "103woot"); //0
    val = atoi(str);
    printf("Str = %s,Int = %d\n", str, val);
    return(0); }
