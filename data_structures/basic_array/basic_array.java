/**
 * oh hello java! I have missed you!
 * @author Susan Lunn
 * Just a basic array
 */


class BasicArray{

    public static void main(String args[]){
        int[] array = new int[6];
        System.out.print("[");
        for(int i = 0; i < 6; i++){
            array[i] = i + 1;
            if(i < 5)
                System.out.print(array[i] + ", ");
            else
                System.out.print(array[i]);
        }
        System.out.println("]");
    }

}


