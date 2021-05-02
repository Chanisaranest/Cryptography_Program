#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int inputDorE();
int Hill(int num);
int DecodeH(char alphabetB[]);
int EncodeH(char alphabetB[]);
int Shift(int num);
int DecodeC(char alphabetB[],char alphabetS[]);
int EncodeC(char alphabetB[],char alphabetS[]);
int Vn(int num);
int DecodeV(char alphabetB[]);
int EncodeV(char alphabetB[]);

// mainของโปรแกรม รับค่าเริ่มต้นว่าจะต้องการใช้รหัสแบบไหน
int main(){
    int number;
    int check = 0;
    system("cls || clear");
    printf("\n=====================================\n");
    printf("\n");
    printf("\tCryptography Program\n\n");
    printf("\t[ 1 ] Shift Cipher\n");
    printf("\t[ 2 ] Vigenère Cipher\n");
    printf("\t[ 3 ] Exit\n\n");
    printf("=====================================\n");
    printf("\n\tWhat do you want?(Enter number 1 or 2 or 3): ");
    scanf("%d", &number);
    // เงื่อนไขเช็กว่ารับค่ามาถูกต้องมั้ย
    if(number != 1 && number != 2 && number != 3){
        printf("\n=====================================\n");
        main();
    }
    else if(number != 3){
        int number2 = inputDorE();
        if(number2 == 3){
            check = 1;
        }
        // กรณีใช้รูปแบบ ซีซาร์
        else if(number == 1){
            Shift(number2);
        }
        //กรณีใช้แบบวินแนร์
        else if(number == 2){
            Vn(number2);
        }
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
    system("cls || clear");
    printf("\n=====================================\n");
    printf("\n\t[ 1 ] Decoding\n");
    printf("\t[ 2 ] Encoding\n");
    printf("\t[ 3 ] Main Menu\n\n");
    printf("\n=====================================\n\n");
    printf("\tWhat do you want?(Enter number 1 or 2): ");
    scanf("%d", &number2);
    if(number2 != 1 && number2 != 2 && number2 != 3){
        number2 = inputDorE();
    }
    else{
    }
    return number2;
}

// การทำงานของรหัสแบบซีซาร์
int Shift(int num){
    system("cls || clear");
    char alphabetB[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alphabetS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    printf("\n=====================================\n");
    if(num == 1){
        DecodeC(alphabetB, alphabetS);
    }
    else{
        EncodeC(alphabetB, alphabetS);
    }
    return 0;
}

// การทำงานของรหัสแบบวินแนร์
int Vn(int num){
    system("cls || clear");
    printf("\n=====================================\n");
    char alphabetB[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    if(num == 1){
        DecodeV(alphabetB);
    }
    else{
        EncodeV(alphabetB);
    }
    return 0;
}

// Decode Shift
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

// Encode Shift
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
    return 0;
}

// Decode วินแนร์
int DecodeV(char alphabetB[]){
    char key[201];
    char text[201];
    int i = 0, k=0;
    printf("\n\tVigenere Cipher Decryption.\n");
    printf("\n\n\tKeyword?(Only alphabet) : ");
    scanf("%s", &key);
    printf("\n\tText? : ");
    scanf(" %[^\n]s", &text);
    while(i<strlen(text)){
        int a = -1;
        int b = -1;
        for(int j=0;j<26;j++){
            if(tolower(text[i])==alphabetB[j] || toupper(text[i])==alphabetB[j]){
                a = j;
            }
            if(tolower(key[k%strlen(key)])==alphabetB[j] || toupper(key[k%strlen(key)])==alphabetB[j]){
                b = j;
            }
            if(a!= -1 && b != -1){
                break;
            }

        }
        float num = a-b;
        num = num/26;
        num = (a-b)-floor(num)*26;
        int num_i = num;
        if(islower(text[i])){
            text[i] = tolower(alphabetB[num_i]);
        }
        else if(isupper(text[i])){
            text[i] = alphabetB[num_i];
        }
        if(isalpha(text[i])){
            k++;
        }
        i++;
    }

    printf("\n       Decrypted Text: %s", text);
    printf("\n\n=====================================\n");
    return 0;
}

// Encode วินแนร์
int EncodeV(char alphabetB[]){
    char key[201];
    char text[201];
    int i = 0, k=0;
    printf("\n\tVigenere Cipher Encryption.\n");
    printf("\n\n\tKeyword?(Only alphabet) : ");
    scanf("%s", &key);
    printf("\n\tText? : ");
    scanf(" %[^\n]s", &text);
    while(i<strlen(text)){
        int a = -1;
        int b = -1;
        for(int j=0;j<26;j++){
            if(tolower(text[i])==alphabetB[j] || toupper(text[i])==alphabetB[j]){
                a = j;
            }
            if(tolower(key[k%strlen(key)])==alphabetB[j] || toupper(key[k%strlen(key)])==alphabetB[j]){
                b = j;
            }
            if(a!= -1 && b != -1){
                break;
            }

        }
        float num = a+b;
        num = num/26;
        num = (a+b)-floor(num)*26;
        int num_i = num;
        if(islower(text[i])){
            text[i] = tolower(alphabetB[num_i]);
        }
        else if(isupper(text[i])){
            text[i] = alphabetB[num_i];
        }
        if(isalpha(text[i])){
            k++;
        }
        i++;
    }
    printf("\n       Encrypted Text: %s", text);
    printf("\n\n=====================================\n");
    return 0;
}
