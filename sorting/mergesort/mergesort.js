
function split(array){
    if(array.length < 2){
        return array;
    }
    var middle = Math.floor(array.length / 2);
    var left = [];
    var right = []

    for(i = 0; i < middle; i++){
        left[i] = array[i];
        right[i] = array[i+middle];
    }

    return merge(split(left), split(right));
}

function merge(left, right){
    var pt_left = 0;
    var pt_right = 0;
    var temp = [];
    while(pt_left < left.length && pt_right < right.length){
        if(left[pt_left] <= right[pt_right]){
            temp.push(left[pt_left]);
            pt_left++;
        }
        else{
            temp.push(right[pt_right]);
            pt_right++;
        }
    }
    while(pt_left < left.length){
        temp.push(left[pt_left]);
        pt_left++;
    }
    while(pt_right < right.length){
        temp.push(right[pt_right]);
        pt_right++;
    }

    return temp;
}

var array = [6,5,3,8,1,7,4,2];
console.log("Unsorted list is: " + array);
array = split(array);
console.log("Sorted list is: " + array);
