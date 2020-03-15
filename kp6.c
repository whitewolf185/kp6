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
    int ID;
    char lastname[32];
    char init [2];
    int number;
    int wight;
    char destination[32];
    char time[5];
    bool got_change;
    bool got_children; //9 параметров
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
            if(man.ID == str_to_int(args[2],log10(man.ID)) || compare_str(man.destination, args[2],32) ||
            compare_str(man.lastname, args[2], 32) || compare_str(man.init,args[2], 2) || man.number == str_to_int(args[2],2) || man.wight == str_to_int(args[2],3) ||
            compare_str(man.time,args[2],5) ) {// сумки должны быть двух знаков,вес - 3-х знаков, наличие детей обозначается true или false
                printf("%d %s %s %d %d %s %s ",man.ID , man.lastname, man.init, man.number, man.wight, man.destination, man.time);
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


        for(int param=1; param<10; param++){
            int count=0;
            while(args[param+1][count] > 0) count++;//подсчет символов
            if(param==1) let_str_str(man.lastname, args[param+1], count);
            if(param==2) man.name=argv[param+1][0];
            if(param==3) record.patron=argv[param+1][0];
            if(param==4){
                if(argv[param+1][0]=='m' || argv[param+1][0]=='f') record.gender=(argv[param+1][0]=='f'? female:male);
                else{
                    printf("Invalid gender. Check your input\n");
                    return 4;
                }
            }
            if(param==5){
                int number=str_to_int(argv[param+1], count);
                if(number==-1){
                    printf("Invalid group number. Check your input\n");
                    return 4;
                }
                else record.group_number=str_to_int(argv[param+1], count);
            }
            if(param==6) record.group_letter=argv[param+1][0];
            if(param==7) let_str_str(record.higher_education, argv[param+1], count);
            if(param==8) let_str_str(record.work, argv[param+1], count);
            if(param==9) let_str_str(record.army, argv[param+1], count);
        }

        FILE *file = NULL;
        file = fopen(args[10], "ab");
        if(file){//это просто проверка на существование файла
            fwrite(&man, sizeof(data), 1, file);
            fclose(file);
            printf("Successfully added. ID: %d\n", man.ID);
            return 0;
        }
        else{
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

