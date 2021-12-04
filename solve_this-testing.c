#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char op[] = "(0+0-0)*0+0^(0-0)";
    int angka[] = {6,5,4,3,2,1,0};

    int digitke = -1;
    for (int i = 0; i < strlen(op); i++){
        if (op[i] == '0'){
           digitke++;
        }
        if (op[i] == '('){
            int digit_awal = digitke;
            int pang[32];
            int k = 0;
            for (int j = i; j < strlen(op); j++){
                if (op[j] == '0'){
                    digitke++;
                    pang[k] = digitke;
                    k++;
                }
                else if (op[j] == ')'){
                    printf("\n");
                    for (k = 0; k < digitke - digit_awal; k++){
                        printf("\n%d", angka[pang[k]]);
                    }
                    i = j;
                    break;
                }
            }
        }
        
    }
    printf("\nindex digit terakhir: %d", digitke);
    
    // Proses:
    // Hasil dari 6+5*(4+3)^2/1 = 6 + 5 * (7) ^ 2 / 1 = 6 + 5 * 49 / 1 = 6 + 245 / 1 = 6 + 245 
    // = 251
}
