//https://leetcode.com/problems/top-k-frequent-elements/description/
//N log n 

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        //hashmap of frequency
        Map<Integer,Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++){
            Integer value = map.get(nums[i]);

            if(value == null){
                map.put(nums[i], 1);
            }    

            else {
                map.put(nums[i], value + 1);
            }
        }

       

        //sort the entryset by value using a comparator
        TreeSet<Map.Entry<Integer,Integer>> sortedVals = new TreeSet<>(new ElementComparator());
        sortedVals.addAll(map.entrySet());

      
        //add top k values in sorted set to result
        int[] result = new int[k];
        int j = 0;
        
        for(Map.Entry<Integer,Integer> entry : sortedVals){
            if(j < k){
                result[j] = entry.getKey();
                j++;
            }
        }

        return result;

    }

    class ElementComparator implements Comparator<Map.Entry<Integer,Integer>>{
        public int compare(Map.Entry<Integer,Integer> e1, Map.Entry<Integer,Integer> e2) {
            //sort in descending order by values
            if(e2.getValue() != e1.getValue()){
            return e2.getValue() - e1.getValue();
            }
            else {return 
                e2.getKey() - e1.getKey();
            }
        }

    }


}