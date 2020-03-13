#include <stdio.h>
#include <math.h>
#define log10(n) floor(log(n))
typedef enum boolean{true=1, false=0} bool;


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
    bool got_children;
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
            if(man.ID == str_to_int(args[2],log10(man.ID)) || man.destination == args[2] || man.got_change == str_to_bool(args[2]) ||
            man.lastname == args[2] || man.init == args[2] || man.number == str_to_int(args[2],2) || man.wight == str_to_int(args[2],2) ||
            man.time == args[2] || man.got_children == str_to_bool(args[2])) {// сумки и вес должны быть двух знаков, наличие детей обозначается true или false
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
        printf("No such man in DB");
        return 2;
    }

    //add
    if (args[1][0] == 'a'){

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
Волков, МА, 3, 42, Марс, 4:20, да, 0
Зубенко, МП, 3, 20, Сицилия, 12:00, 0, 0


 */

