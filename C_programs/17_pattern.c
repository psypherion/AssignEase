///Write a Program to display this Pattern : 
///*
///*
///*
///**
///****

#include<stdio.h>

int main(){
    int rows = 5;
    int count = 3;
    int num=0;
    for(int i=0;i<=rows;i++){
        if(i<count){
            printf("*\n");
        }
        else if (i==count){
            continue;
        }
        else{
            num += 2;
            for(int j=0;j<num;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}