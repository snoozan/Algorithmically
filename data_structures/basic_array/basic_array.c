/**
 * basic_array.c
 * author: Susan Lunn
 */

#include <stdio.h>

int main(){
    int example_array [5];

    //first we need to fill the array with 0s
    for(int i = 0; i < 5; i++){
        example_array[i] = 0;
    }

    printf("[");
    for(int i = 0; i < 5; i++){
        example_array[i] = i + 1; // can't do i++, because that will return i and then increment that value
        printf("%d", example_array[i]);
        if(i < 4){
            printf(", ");
        }
    }
    printf("]\n");

}
