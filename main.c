#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char *remove_white_spaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' '){
            str[j++] = str[i];
        } 
		i++;
	}
	str[j] = '\0';
	return str;
}

int main(){
    char str[256];
    int angka[512];
    char operator[512];

    scanf("%[^\n]", str);

//REMOVE WHITE-SPACE
    remove_white_spaces(str);
//-----------------------------

//DIVIDER ANGKA
    char *ptr = str;
    int i = 0;
    while (*ptr) {
        if ( isdigit(*ptr) ) {
            int val = (int)strtol(ptr, &ptr, 10);
            angka[i] = val;
            i++;
        } else {
            ptr++;
        }
    }
//----------------------------------------------------

//DIVIDER OPERATOR
    int j = 1;
    for (int k = 0; k < str[k]; k++){
        if (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' || str[k] == '(' || str[k] == ')' || str[k] == '^'){
            operator[j] = str[k];
            operator[j-1] = '0';
            operator[j+1] = '0';
            j += 2;
        }
    }
//----------------------------------------------------------------------------------

// OPERATOR CLEANUP
    int len_op = strlen(operator);
    for (int i = 0; i < len_op; i++){
        if (operator[i] == '('){
            operator[i-1] = '\0';
            for (j = i; j < len_op; j++){
                operator[j-1] = operator[j];
            }
        }
        if (operator[i] == ')'){
            operator[i+1] = '\0';
            for (j = i; j < len_op; j++){
                operator[j+1] = operator[j+2];
            }
        }
    }
    len_op = 0;
    for (int i = 0; i < strlen(operator); i++){
        if (operator[i] == '0' || operator[i] == '+' || operator[i] == '-' || operator[i] == '/' || operator[i] == '*' || operator[i] == '(' || operator[i] == ')' || operator[i] == '^'){
            len_op += 1;
        }
    }
    for (int i = 0; i < len_op; i++){
        if (operator[i] == '(' || operator[i] == ')'){
            len_op -= 1;
            operator[len_op] = 0;
            break;
        }
    }

//DIGIT COUNTING - MELIHAT BANYAK DIGIT DI PERHITUNGAN
    int len_dig = 0;
    for (int i = 0; i < len_op; i++){
        if (operator[i] == '0'){
            len_dig++;
        }
    }

/*
//Prioritas Perhitungan//Masih Salah//
    int digke = -1;
    for (int i = 0; i < len_op; i++){
        if (operator[i] == '0'){
            digke += 1;
        }
        else if (operator[i] == '(');
            for (int j = i; j < len_op; j++){
                if (operator[j] == '0'){
                    digke += 1;
                }
                else if (operator[j] == ')'){
                    printf("%d\n", digke-1);
                    i += j + 1;
                    break;
                }

            }
        }
    printf("%d\n", digke);
*/

// PRINTING ANGKA, OPERATOR, KURUNG (For Testing)
    printf("\n");
    printf("%s", str);
    printf("\n");
    printf("%s", operator);
    printf("\n");
    //printf("\npanjang operasi dengan operator: %d\n", len_op);

    for (int i = 0; i < len_dig; i++){
        printf("%d ", angka[i]);
    }
    printf("\nBanyak digit: %d", len_dig);
//---------------------------------------------

}

//TESTING INPUT: 20 - 12 + ( 12 - 10 ) + 13 ^ 2 * ( 3 + 2 ) - 5

//KAMUS: str = input string, angka = angka yang didapatkan dari input dalam bentuk int, operator = operator yang didapatkan dari input,
//len_op = panjang dari string operator, len_dig = banyak nilai angka dari input.
