//https://leetcode.com/problems/two-sum/description/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSumBrute = function(nums, target) {
    for(let i = 0; i < nums.length-1; i ++){
        for(let j = i+1; j < nums.length; j++)
            {
                if(nums[i]+nums[j] === target)
                    return [i,j];
            }            
    }
};

var twoSumObject = function(nums, target){
    let hash = {};
    for(let i = 0; i < nums.length; i ++)
    {
        let comp = target - nums[i];
        if(hash[comp]) return [hash[comp], i]
        hash[nums[i]] = i;
    }
}
