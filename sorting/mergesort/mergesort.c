/*
 * Author: Susan Lunn
 * filename: mergesort.c
 * Use: implements mergesort in c/
 * I use the stack for this entire thing -> no mallocs
 */


#include <stdio.h>
#include <stdlib.h>


void merge(int left_num, int left[], int right_num, int right[], int array[]){
    int pt_left = 0; //first element in left list
    int pt_right = 0; //first element in right list
    int index = 0;

    while(pt_left < left_num && pt_right < right_num){ //each are not at the end of their list
        if(left[pt_left] <= right[pt_right]){
            //swap values
            array[index] = left[pt_left];
            pt_left++;
            index++;
        }
        else{
            //swap values
            array[index] = right[pt_right];
            pt_right++;
            index++;
        }
    }
    while(pt_left < left_num){ //will only execute if right has gone past its right_num
        array[index] = left[pt_left];
        pt_left++;
        index++;
    }
    while(pt_right < right_num){ //will only execute if left has gone past its left_num
        array[index] = right[pt_right];
        pt_right++;
        index++;
    }
}

void split(int length, int array[]){
    if(length < 2){
        return; //don't need to return an item
    }

    int left_num = length/2; //the first half of elements
    int right_num = length - left_num; //the remainder of elements

    int left[left_num];
    int right[right_num];

    for(int i = 0; i < left_num; i++){
        left[i] = array[i];
    }

    for(int j = 0; j < right_num; j++){
        right[j] = array[j + left_num]; //the second half
    }


    split(left_num, left); //split them up

    split(right_num, right); //split them up

    merge(left_num, left, right_num, right, array); //split them up
};

int main(){
    int array[8] = {6,5,3,8,1,7,4,2};

    printf("The unsorted list is: [");
    for(int i = 0; i < 8; i++){
        printf("%d", array[i]);
        if(i < 7){
            printf(", ");
        }
    }
    printf("]\n");

    split(8, array);

    printf("The current state of sorted is: [");
    for(int i = 0; i < 8; i++){
        printf("%d", array[i]);
        if(i < 7){
            printf(", ");
        }
    }
    printf("]\n");
}


