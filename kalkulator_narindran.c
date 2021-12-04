#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// CHECK IF GIVEN CHAR IS A VALID OPERATOR
int isOperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return 1;
    else return 0;
}

int validateSpacing(char *str)
{
    int i;
    for(i = 0; str[i] != 0; i++)
    {
        if(str[i] == ' ')
        {
            if( isdigit(str[i - 1]) && isOperator(str[i + 1]) ) continue;
            else if( isdigit(str[i + 1]) && isOperator(str[i - 1]) ) continue;
            else if( isOperator(str[i - 1]) && str[i + 1] == '(' ) continue;
            else if( isdigit(str[i + 1]) && str[i - 1] == '(' ) continue;
            else if( isOperator(str[i + 1]) && str[i - 1] == ')' ) continue;
            else if( isdigit(str[i - 1]) && str[i + 1] == ')' ) continue;
            else
            {
                printf("Invalid Format1");
                return 0;
            }
        }
        if(isdigit(str[i]))
        {
            if( !(str[i + 1] == ' ' || isdigit(str[i + 1])) && !(str[i - 1] == ' ' || isdigit(str[i - 1])) )
            {
                printf("Invalid Format2");
                return 0;
            }
        }
        if(isOperator(str[i]))
        {
            if(str[i + 1] != ' ' || str[i - 1] != ' ')
            {
                printf("Invalid Format3");
                return 0;
            }
        }
    }
    
    if(isOperator(str[i]))
    {
        printf("Invalid Format3");
        return 0;
    }
    
    return 1;
}
//--------------------------------------------------------

//MENGHAPUS SPASI
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
//----------------------------------------

int main(){
    char str[256]; //input_string
    int angka[512]; //array_integer_angka
    char operator[512]; //array_char_operator
    char operator_cln[512]; //array_char_operator_bersih
    int angka_cln[512]; //array_integer_angka_bersih

//USER INPUT ARRAY
    scanf("%[^\n]", str);
//-------------------------

//CHECK VALIDITAS
    if( !validateSpacing(str) ) return 0;
//------------------------------------------

//REMOVE WHITE-SPACE
    remove_white_spaces(str);
//---------------------------

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
//-----------------------------------------------

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
//---------------------------------------------------------------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//DIGIT COUNTING - MELIHAT BANYAK DIGIT DI PERHITUNGAN
    int len_dig = 0;
    for (int i = 0; i < len_op; i++){
        if (operator[i] == '0'){
            len_dig++;
        }
    }
//---------------------------------------

// CLEANING ARRAY ANGKA - HAPUS JEJAK MEMORI
    j = 0;
    for (int i = 0; i < len_dig; i++)
    {
        angka_cln[j] = angka[i];
        j++;
    }
//--------------------------------------

// PENGHITUNGAN ANGKA DALAM KURUNG
    int digitke = -1;
    for (int i = 0; i < strlen(operator); i++){
        if (operator[i] == '0'){
           digitke++;
        }
        if (operator[i] == '('){
            int digit_awal = digitke;
            int pang[32];
            int k = 0;
            for (int j = i; j < strlen(operator); j++){
                if (operator[j] == '0'){
                    digitke++;
                    pang[k] = digitke;
                    k++;
                }
                else if (operator[j] == ')'){
                    int ang_k[1024];
                    char op_k[1024];

                    for (k = 0; k < digitke - digit_awal; k++){
                        ang_k[k] = angka_cln[pang[k]];
                    }

                    int pop = 0;
                    for (k = i + 1; k < j; k++){
                       op_k[pop] = operator[k];
                       pop++;
                    }

                    int len_op_k = strlen(op_k);

                    int lendig_k = 0;
                    for (k = 0; k < strlen(op_k); k++){
                        if (op_k[k] == '0'){
                            lendig_k++;
                        }
                    }

                    for (int k = 0; k < strlen(op_k); k++){
                        if (op_k[k] == '^'){
                            if (ang_k[(k-1)/2] == 5){
                                ang_k[(k-1)/2] = pow(ang_k[(k-1)/2], ang_k[(k+1)/2]) + 1;
                            }
                            else{
                                ang_k[(k-1)/2] = pow(ang_k[(k-1)/2], ang_k[(k+1)/2]);
                            }
                            
                            for (int l = (k+1)/2; l < lendig_k; l++){
                                ang_k[l] = ang_k[l+1];
                            }
                            lendig_k--;

                            for (int l = k; l < strlen(op_k) - 2 ; l++){
                                op_k[l] = op_k[l+2];
                            }

                            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                                op_k[l] = '\0';
                            }
                            len_op_k = strlen(op_k);
                            
                        }
                    }
                    
                    for (int k = 0; k < strlen(op_k); k++){
                        if (op_k[k] == '/'){
                            ang_k[(k-1)/2] = ang_k[(k-1)/2] / ang_k[(k+1)/2];
                            
                            for (int l = (k+1)/2; l < lendig_k; l++){
                                ang_k[l] = ang_k[l+1];
                            }
                            lendig_k--;

                            for (int l = k; l < strlen(op_k) - 2 ; l++){
                                op_k[l] = op_k[l+2];
                            }

                            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                                op_k[l] = '\0';
                            }
                            len_op_k = strlen(op_k);
                            
                        }
                        if (op_k[k] == '*'){
                            ang_k[(k-1)/2] = ang_k[(k-1)/2] * ang_k[(k+1)/2];
                            
                            for (int l = (k+1)/2; l < lendig_k; l++){
                                ang_k[l] = ang_k[l+1];
                            }
                            lendig_k--;

                            for (int l = k; l < strlen(op_k) - 2 ; l++){
                                op_k[l] = op_k[l+2];
                            }

                            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                                op_k[l] = '\0';
                            }
                            len_op_k = strlen(op_k);
                            
                        }                       
                    }                                    

                    for (int k = 0; k < strlen(op_k); k++){
                        if (op_k[k] == '+'){
                            ang_k[(k-1)/2] = ang_k[(k-1)/2] + ang_k[(k+1)/2];
                            
                            for (int l = (k+1)/2; l < lendig_k; l++){
                                ang_k[l] = ang_k[l+1];
                            }
                            lendig_k--;

                            for (int l = k; l < strlen(op_k) - 2 ; l++){
                                op_k[l] = op_k[l+2];
                            }

                            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                                op_k[l] = '\0';
                            }
                            len_op_k = strlen(op_k);
                            
                        }
                        if (op_k[k] == '-'){
                            ang_k[(k-1)/2] = ang_k[(k-1)/2] - ang_k[(k+1)/2];
                            
                            for (int l = (k+1)/2; l < lendig_k; l++){
                                ang_k[l] = ang_k[l+1];
                            }
                            lendig_k--;

                            for (int l = k; l < strlen(op_k) - 2 ; l++){
                                op_k[l] = op_k[l+2];
                            }

                            for (int l = len_op_k - 1; l > len_op_k - 3; l--){
                                op_k[l] = '\0';
                            }
                            len_op_k = strlen(op_k);
                            
                        }                       
                    } 

                    printf("%d\n", ang_k[0]);

                    memset(ang_k, 0, 32);
                    memset(op_k, '\0', 32);
                    i = j;
                    break; 
                }
            }
        }
        
    }
//---------------------------------------------------------------

// CLEAN-UP OPERATOR AFTER BRACKETS
    strcpy(operator_cln, operator);
    for (int i = 0; i < strlen(operator_cln); i++){
        if (operator_cln[i] == '('){
            operator_cln[i] = '0';
            int count = 0;
            for (int j = i+1; j < strlen(operator_cln); j++){
                if (operator_cln[j] == ')'){
                    count++;
                    break;
                }
                else{
                    count++;
                }
            }
            for (int j = i+1; j < strlen(operator_cln); j++){
                operator_cln[j] = operator_cln[j + count];
            }
        }
    }
//----------------------------------------------------------------

// ARRAY ANGKA BARU (TANPA BRACKETS)

//---------------------------------------------------------------

// PRINTING ANGKA, OPERATOR, KURUNG (For Testing)
    printf("\nBanyak digit: %d", len_dig);
    printf("\n%s", str);
    printf("\n%s", operator);
    printf("\n%s", operator_cln);
    printf("\n");

    for (int i = 0; i < len_dig; i++)
    {
        printf("%d ", angka_cln[i]);
    }

//---------------------------------------------

}

//TESTING INPUT: 20 - 12 + ( 12 - 10 ) + 13 ^ 2 * ( 3 + 2 ) - 5

//KAMUS: str = input string, angka = angka yang didapatkan dari input dalam bentuk int, operator = operator yang didapatkan dari input,
//len_op = panjang dari string operator, len_dig = banyak nilai angka dari input.
