/*
 * Author: Susan Lunn
 * filename: mergesort.c
 * Use: implements mergesort in c/
 */


#include <stdio.h>
#include <stdlib.h>


/*
 * I use int* because fuck that array business
 */
void merge(int begin, int middle, int end, int* array, int* sorted){
    int pt_left = begin; //first element in left list
    int pt_right = middle; //first element in right list


    for(int i = begin; i < end; i++){
        if(pt_left < middle && (pt_right >= end || array[pt_left] < array[pt_right])){
            sorted[i] = array[pt_left];
            pt_left++;
        }
        else{
            sorted[i] = array[pt_right];
            pt_right++;
        }
    }

    printf("beginning is: %d middle is: %d end is: %d \n", begin, middle, end);
    printf("The current state of sorted is: [");
    for(int i = 0; i < middle; i++){
        printf("%d", sorted[i]);
        if(i < middle-1){
            printf(", ");
        }
    }
    printf("]\n");

};

void copy(int begin, int end, int* array, int* sorted){
    for(int i = begin; i < end; i++){
        sorted[i] = array[i];
    }
}

/*
 * I use int* because fuck that array business
 */
void split(int left, int right, int* array, int* sorted){
    if(right - left < 2){
        return; //don't need to return an item
    }

    int middle = (left+right)/2;

    //debugging
    //printf("The left array currently is: [");
    //for(int i = 0; i < middle; i++){
    //    printf("%d", array[i]);
    //    if(i < middle-1){
    //        printf(", ");
    //    }
    //}
    //printf("] ");

    //printf("The right array currently is: [");
    //for(int i = middle; i < right; i++){
    //    printf("%d", array[i]);
    //    if(i < right-1){
    //        printf(", ");
    //    }
    //}
    //printf("]\n");

    split(left, middle, array, sorted); //split them up
    split(middle, right, array, sorted); //split them up

    merge(left, middle, right, array, sorted); //split them up
    copy(left, right, array, sorted);

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

    int* sorted_array = malloc(sizeof(int) * 8);//using the heap like a pleb
    split(0, 7, &array[0], sorted_array);
    printf("The current state of sorted is: [");
    for(int i = 0; i < 8; i++){
        printf("%d", array[i]);
        if(i < 7){
            printf(", ");
        }
    }
    printf("]\n");
    free(sorted_array);
}


