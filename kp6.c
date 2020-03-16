#include <stdio.h>
#include <math.h>
#define log10(n) floor(log(n))
typedef enum boolean{true=1, false=0} bool;

bool compare_str(char x[], char y[], int size){
    for(int i=0; i<size; i++){
        if(x[i]==0 && y[i]==0) break;
        if(x[i]!=y[i]) return false;
    }
    return true;
}

void let_str_str(char x[], char y[], int size){
    for(int i=0; i<size; i++) x[i]=y[i];
}

int str_to_int(char x[], int size){
    int ans=0;
    int pos=1;
    for(int i=size-1; i>=0; i--){
        if(x[i]<'0' || x[i]>'9') return -1;
        ans+=pos*(x[i]-'0');
        pos*=10;
    }
    return ans;
}

bool str_to_bool(char x[]){
    if(x == "false"){
        return false;
    }
    else{
        return true;
    }
}

typedef struct data {
    char lastname[32]; //1
    char init [2]; // 2
    int number; // 3
    int wight; // 4
    char destination[32]; // 5
    char time[5]; // 6
    bool got_change; // 7
    bool got_children; //8 параметров
} data;


void clear(char x[], int size){
    for(int i=0; i<size; i++) x[i]=0;
}

int main(int num, char* args[]) {
    //request
    if (args[1][0] == 'q'){
        FILE *file=NULL;
        file = fopen(args[3], "rb");
        data man;
        while(fread(&man, sizeof(data), 1, file)){
            if(compare_str(man.destination, args[2],32) || compare_str(man.lastname, args[2], 32) || compare_str(man.init,args[2], 2) ||
            man.number == str_to_int(args[2],2) || man.wight == str_to_int(args[2],3) ||
            compare_str(man.time,args[2],5) ) {// сумки должны быть двух знаков,вес - 3-х знаков, наличие детей обозначается true или false
                printf("%s %s %d %d %s %s ", man.lastname, man.init, man.number, man.wight, man.destination, man.time);
                if(man.got_change){
                    printf("true ");
                }
                else{
                    printf("false ");
                }

                if(man.got_children){
                    printf("true");
                }
                else{
                    printf("false");
                }
                fclose(file);
                return 0;
            }
        }
        fclose(file);
        printf("No such man in DB\n");
        return 2;
    }

    //add
    if (args[1][0] == 'a'){
        data man;
        clear(man.lastname, 32);
        clear(man.init, 2);
        clear(man.destination, 32);
        clear(man.time, 5);


        for(int param=1; param<9; param++){
            int count=0;
            while(args[param+1][count] > 0) count++;//подсчет символов
            if(param==1) {let_str_str(man.lastname, args[param+1], count);}
            if(param==2) {let_str_str(man.init, args[param+1], count);}
            if(param==3) {man.number = str_to_int(args[param+1],2);}
            if(param==4){
                man.wight = str_to_int(args[param+1], 3);
            }
            if(param==5){
                let_str_str(man.destination, args[param + 1], count);
            }
            if(param==6) {
                let_str_str(man.time, args[param+1], 5);
            }
            if(param==7) {
                if(args[param+1] == "true"){
                    man.got_change = true;
                }
                else{
                    man.got_change = false;
                }
            }
            if(param==8) {
                if(args[param+1] == "true"){
                    man.got_children = true;
                }
                else{
                    man.got_children = false;
                }
            }
        }

        FILE *file = NULL;
        file = fopen(args[10], "ab");
        if(file){//это просто проверка на существование файла
            fwrite(&man, sizeof(data), 1, file);
            fclose(file);
            printf("Successfully added. ");
            return 0;
        }
        else{
            printf("St goes wrong with file\n");
            fclose(file);
            return 1;
        }

    }

    //delete
    if (args[1][0] == 'd'){

    }

    //making my task
    if(args[1][0] == 'm'){

    }
    return 0;
}
/*
Волков, МА, 03, 042, Марс, 04:20, да, 0
Зубенко, МП, 03, 020, Сицилия, 12:00, 0, 0


 */

