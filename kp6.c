#include <stdio.h>
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
    char init [3]; // 2
    int number; // 3
    int wight; // 4
    char destination[32]; // 5
    char time[6]; // 6
    char got_change[6]; // 7
    char got_children[6]; //8 параметров
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
                printf("%s %s %d %d %s %s %s %s\n", man.lastname, man.init, man.number, man.wight, man.destination, man.time, man.got_change, man.got_children);
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
        clear(man.init, 3);
        clear(man.destination, 32);
        clear(man.time, 6);
        clear(man.got_change,6);
        clear(man.got_children, 6);


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
                let_str_str(man.got_change, args[param+1], 6);
            }
            if(param==8) {
                let_str_str(man.got_children, args[param+1], 6);
            }
        }
 //       printf("%d\n",man.number);
        FILE *file = NULL;
        file = fopen(args[10], "ab");
        if(file){//это просто проверка на существование файла
            fwrite(&man, sizeof(data), 1, file);
            fclose(file);
            printf("Successfully added. \n");
            return 0;
        }
        else{
            printf("St goes wrong with file.\n");
            fclose(file);
            return 1;
        }

    }

    //show all DB
    if (args[1][0] == 's'){
        FILE *base=NULL;
        base=fopen(args[2], "rb");
        if(base){
            int j=1;
            data record;
            while(fread(&record, sizeof(data), 1, base)){
                printf("%d | %s %s %d %d %s %s %s %s\n", j, record.lastname, record.init, record.number, record.wight, record.destination, record.time, record.got_change, record.got_children);
                j++;
            }
            fclose(base);
            return 0;
        }
        else{
            fclose(base);
            printf("ST goes wrong with file. Please, check -h\n");
            return 1;
        }
    }

    //delete
    if (args[1][0] == 'd'){
        FILE *base=NULL;
        base=fopen(args[3], "rb");
        FILE *tmp=NULL;
        tmp=fopen("tmp_file", "wb");
        if(tmp && base) {
            int size = 0;
            while (args[2][size] > 0) {//подсчет цифр в числе
                size++;
            }
            int n = str_to_int(args[2], size);
            int j = 1;
            data record;
            while (fread(&record, sizeof(data), 1, base) > 0) {
                if (j != n) {
                    fwrite(&record, sizeof(data), 1, tmp);
                }
                j++;
            }
            if (n >= j || 1 > n) {
                fclose(tmp);
                remove("tmp_file");
                fclose(base);
                printf("Record %d in %s does not exist\n", n, args[3]);
                return 4;
            } else {
                fclose(base);
                base = fopen(args[3], "wb");
                fclose(tmp);
                tmp = fopen("tmp_file", "rb");
                while (fread(&record, sizeof(data), 1, tmp) > 0) {
                    fwrite(&record, sizeof(data), 1, base);
                }
                fclose(base);
                fclose(tmp);
                remove("tmp_file");
                printf("Successfully removed %d record from %s\n", n, args[3]);
                return 0;
            }
        }
        else{
            fclose(base);
            fclose(tmp);
            remove("tmp_file");
            printf("ST goes wrong with file. Try -h\n");
            return 1;
        }
    }

    //making my task
    if(args[1][0] == 'm'){
        FILE *file = NULL;
        file = fopen(args[3], "rb");
        data man;
        bool not_exist = true;
        int size = 0;
        while (args[2][size] > 0) {//подсчет цифр в числе
            size++;
        }
        int p = str_to_int(args[2], size);
        int j = 1;
        if(file){
            while(fread(&man, sizeof(data), 1, file)){
                if(p < man.number){
                    printf("%d | %s %.2s %d %d %s %s %s %s\n", j, man.lastname, man.init, man.number, man.wight, man.destination, man.time, man.got_change, man.got_children);
                    not_exist = false;
                }
                j++;
            }
            if(not_exist){
                fclose(file);
                printf("not exist\n");
                return 1;
            }
            fclose(file);
           return 0;
        }
        else{
            fclose(file);
            printf("ST goes wrong with file. Check -h\n");
            return 1;
        }
    }
    printf("Wrong parameters. Check -h\n");
    return 1;
}
/*
Волков, МА, 03, 042, Марс, 04:20, да, 0
Зубенко, МП, 03, 020, Сицилия, 12:00, 0, 0


 */

