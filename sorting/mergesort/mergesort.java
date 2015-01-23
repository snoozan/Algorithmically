/**
 * mergesort written in java -> don't reinvent the wheel, use java's built-in objects
 * @author Susan Lunn
 */



public class mergesort {

    private int[] array;
    private int[] sorted;

    public static void main(String args[]){
        int[] array = {6,5,3,8,1,7,4,2};

        System.out.println("The unsorted list is: " + array);

        mergesort merger = new mergesort();
        merger.initSort(array);

        System.out.print("The sorted list is: ");
        for(int num: array){
            System.out.print(num);
        }

        System.out.println("");
    }

    /*
     * Java! Object Orientation! yeah!
     */
    public void initSort(int array[]){
        this.array = array;
        this.sorted = new int[array.length];
        split(0, array.length-1);
    }

    private void split(int left, int right){
        if(left < right){
            int middle = (left + right)/2;
            split(left, middle);
            split(middle+1, right);
            merge(left, middle, right);
        }
    }

    /*
     * this is a more space efficient merge, since we aren't creating N arrays
     * although more difficult to wrap your head around, imo :)
     */
    private void merge(int left, int middle, int right){
        int ptLeft = left;
        int ptRight = middle+1; //the beginning of the right array
        int index = left; //since we're editing the array in place, we keep the index at left instead of 0

        //copy all values into sorted
        for(int i = left; i < right; i++){
            sorted[i] = array[i];
        }

        while(ptLeft <= middle && ptRight <= right){
            if(sorted[ptLeft] <= sorted[ptRight]){
                array[index] = sorted[ptLeft];
                ptLeft++;
            }
            else{
                array[index] = sorted[ptRight];
                ptRight++;
            }
            index++;
        }

        while(ptLeft < left){
            array[index] = sorted[ptLeft];
            index++;
        }

        while(ptRight < right){
            array[index] = sorted[ptRight];
            index++;
        }

    }




}
