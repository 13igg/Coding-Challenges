//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxLen = 0;
    let found = {};
    let len = 0;
    for(let i =0; i<s.length; i++){
        let letter = s[i];
        if(found[letter] >= 0){
          maxLen = len>maxLen?len:maxLen;
          len = 0;
          i = found[letter];
          found = {};
        } 
        else{
            len += 1;
            found[letter] = i;
        }
    }
    maxLen = len>maxLen?len:maxLen;
    
    return maxLen;
};