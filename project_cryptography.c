#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int inputDorE();
int CryptoC(int num);
int DecodeM();
int EncodeM();
int Ceasar(int num);
int DecodeC(char alphabetB[],char alphabetS[]);
int EncodeC(char alphabetB[],char alphabetS[]);


// mainของโปรแกรม รับค่าเริ่มต้นว่าจะต้องการใช้รหัสแบบไหน
int main(){
    int number;
    int check = 0;
    printf("\n=====================================\n");
    printf("\n");
    printf("\t[ 1 ] Hill Cipher\n");
    printf("\t[ 2 ] Caesar Cipher\n");
    printf("\t[ 3 ] Exit\n\n");
    printf("\tWhat do you want?(Enter number 1 or 2): ");
    scanf("%d", &number);
    // เงื่อนไขเช็กว่ารับค่ามาถูกต้องมั้ย
    if(number != 1 && number != 2 && number != 3){
        printf("\n=====================================\n");
        main();
    }
    else if(number != 3){
        printf("\n    -----------------------------    \n");
        int number2 = inputDorE();
        if(number2 == 3){
            check = 1;
        }
        // กรณีใช้รูปแบบ Matrix
        else if(number == 1){
            CryptoC(number2);
        }
        // กรณีใช้รูปแบบ ซีซาร์
        else if(number == 2){
            Ceasar(number2);
        }
        // printf("\n=====================================\n");
    }
    // ปิดโปรแกรม
    if(number == 3){
        check = 2;
    }
    // เช็กว่าต้องการใช้งานต่อหรือปิดโปรแกรม
    while (check != 1 && check != 2)
    {

        printf("\n\tWhat do you want?\n");
        printf("\n  [ 1 ] Continue    [ 2 ] Exit\n");
        printf("\n\tEnter number 1 or 2 : ");
        scanf("%d", &check);
        // printf("\n=====================================\n");
    }
    // ดำเนินต่อ
    if(check == 1){
        main();
    }
    // ปิดโปรแกรม
    else if(check == 2){
        printf("\n=====================================\n");
        printf("\n\t Thank you.");
    }
    return 0;
}

// เช็กว่าเลขที่รับมาตรงตามเงื่อนไขมั้ย
int inputDorE(){
    int number2;
    printf("\n\t[ 1 ] Decoding\n");
    printf("\t[ 2 ] Encoding\n");
    printf("\t[ 3 ] Main Menu\n\n");
    printf("\tWhat do you want?(Enter number 1 or 2): ");
    scanf("%d", &number2);
    if(number2 != 1 && number2 != 2 && number2 != 3){
        printf("\n    -----------------------------    \n");
        number2 = inputDorE();
    }
    else{
        printf("\n    -----------------------------    \n");
    }
    return number2;
}

// การทำงานของรหัสแบบเมทริกซ์
int CryptoC(int num){
    if(num == 1){
        DecodeM();
    }
    else{
        EncodeM();
    }
    return 0;
}

// การทำงานของรหัสแบบเมทริกซ์
int Ceasar(int num){
    char alphabetB[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alphabetS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if(num == 1){
        DecodeC(alphabetB, alphabetS);
    }
    else{
        EncodeC(alphabetB, alphabetS);
    }
    return 0;
}

// Decode Matrix
int DecodeM(){
    printf("\n\tDecode M");
    printf("\n=====================================\n");
}

// Encode Matrix
int EncodeM(){
    printf("\n\tEncode M");
    printf("\n=====================================\n");
}

// Decode Ceasar
int DecodeC(char alphabetB[],char alphabetS[]){
    int key;
    char text[201];
    printf("\n\tCeasar Cipher Decryption.\n");
    printf("\nIf key is right shift, use positive integer ex.1 2 5");
    printf("\nIf key is left shift, use negative integer ex.-1 -2 -5");
    printf("\n\n\tKey? : ");
    scanf("%d", &key);
    printf("\n\tText? : ");
    scanf(" %[^\n]s", &text);
    for(int i = 0; i<strlen(text);i++){
        if(islower(text[i])){
            for(int j=0;j<26;j++){
                if (text[i] == alphabetS[j])
                {
                    float num = j-key;
                    num = num/26;
                    num = (j-key)-floor(num)*26;
                    int num_i = num;
                    text[i] = alphabetS[num_i];
                    break;
                }
            }
        }
        else if(isupper(text[i])){
            for(int j=0;j<26;j++){
                if (text[i] == alphabetB[j])
                {
                    float num = j-key;
                    num = num/26;
                    num = (j-key)-floor(num)*26;
                    int num_i = num;
                    text[i] = alphabetB[num_i];
                    break;
                }
            }
        }
    }
    printf("\n       Decrypted Text: %s", text);
    printf("\n\n=====================================\n");
    return 0;
}

// Encode Ceasar
int EncodeC(char alphabetB[],char alphabetS[]){
    int key;
    char text[201];
    printf("\n\tCeasar Cipher Encryption.\n");
    printf("\nIf you want to right shift, use positive integer ex.1 2 5");
    printf("\nIf you want to left shift, use negative integer ex.-1 -2 -5");
    printf("\n\n\tKey? : ");
    scanf("%d", &key);
    printf("\n\tText? : ");
    scanf(" %[^\n]s", &text);
    for(int i = 0; i<strlen(text);i++){
        if(islower(text[i])){
            for(int j=0;j<26;j++){
                if (text[i] == alphabetS[j])
                {
                    float num = j+key;
                    num = num/26;
                    num = (j+key)-floor(num)*26;
                    int num_i = num;
                    text[i] = alphabetS[num_i];
                    break;
                }
            }
        }
        else if(isupper(text[i])){
            for(int j=0;j<26;j++){
                if (text[i] == alphabetB[j])
                {
                    float num = j+key;
                    num = num/26;
                    num = (j+key)-floor(num)*26;
                    int num_i = num;
                    text[i] = alphabetB[num_i];
                    break;
                }
            }
        }
    }
    printf("\n       Encrypted Text: %s", text);
    printf("\n\n=====================================\n");
}