class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> mp = new HashSet<>();
        for(int num : nums) {
            if(mp.contains(num)) return true;
            mp.add(num);
        }
        return false;
    }
}