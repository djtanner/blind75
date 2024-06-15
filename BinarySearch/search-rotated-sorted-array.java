class Solution {
    public int search(int[] nums, int target) {
        return binSearch(0, nums.length -1, nums, target);
    }


    public int binSearch(int start, int end, int[] nums, int target){

        if(nums[start] == target){return start;}
        
        //base case not found

        if(start >= end){ return -1 ;}

        

        //calc middle

        int middle = (start + end) / 2 ;

        //check if middle is target
        if(nums[middle] == target){
            return middle;
        }

        //decide which half to search
        
        if (nums[start] <= nums[middle]) { // Left half is sorted
            if (target >= nums[start] && target < nums[middle]) {
                return binSearch(start, middle - 1, nums, target);
            } else {
                return binSearch(middle + 1, end, nums, target);
            }
        } else { // Right half is sorted
            if (target > nums[middle] && target <= nums[end]) {
                return binSearch(middle + 1, end, nums, target);
            } else {
                return binSearch(start, middle - 1, nums, target);
            }
        }


    }
}