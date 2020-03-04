#include <stdio.h>
enum boolean{true=1, false=0};
typedef enum boolean bool;


struct data {
    int ID;
    char lastname[32];
    char init [2];
    int number;
    int wight;
    char destination[32];
    char time[5];
    bool got_change;
    bool got_children;
};
typedef struct data data;

void clear(char x[], int size){
    for(int i=0; i<size; i++) x[i]=0;
}
//TODO надо продумать счетчик. скорее всего это будет просто просмотр последнего ID, но это как-то долго
int main(int num, char* args[]) {
    //request
    if (args[1][0] == 'q'){

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

