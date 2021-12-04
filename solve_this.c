#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char op[] = "0-0+0^0*0/0";
    int angka[] = {3,2,3,4,5,5};
}

//OUTPUT = 6 + 5 - 4 ^ 3 * 2 / 1 = 1 + 81 = 82
//Array op adalah representasi perhitungan yang akan dilakukan, dimana '0' adalah posisi dari nilai yang akan di proses.
//dan tanda */ + - ^ adalah operator perhitungannya, dan memilki prioritas tertentu.
//Arrat angka adalah nilai yang akan diproses sesuai dengan proses di array operator.
