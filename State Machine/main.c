/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: ziadayman
 */


#include <stdio.h>

typedef enum{
    STATEA ,STATEB,STATEC
}types;

void STATEA_func(void);
void STATEB_func(void);
void STATEC_func(void);
void state_init(void);

static void (*states[]) (void) = {STATEA_func, STATEB_func, STATEC_func};

static types current;
static int number = 0;


int main(){
    state_init();

    while(1){
        states[current]();
        number++;
    }



    return 0;
}


void state_init(void){
    current = STATEA;
    number = 0;
}
void STATEA_func(void){
    if(number == 2){
        current = STATEB;
        printf("State A\n");
    }

}
void STATEB_func(void){
    if(number == 5){
        current = STATEC;
        printf("State B\n");
    }
}
void STATEC_func(void){
    if(number == 9){
        current = STATEA;
        number = 0;
        printf("State C\n");
    }

}
