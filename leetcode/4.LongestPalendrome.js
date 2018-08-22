//https://leetcode.com/problems/longest-palindromic-substring/description/
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s == null || s.length < 1) return "";
    let maxStart = 0;
    let maxEnd = 0;
    for(let i = 0; i < s.length; i ++){
        let len1 = expandOnCenter(s, i, i);
        let len2 = expandOnCenter(s, i, i+1);
        let curMax = Math.max(len1,len2);
        if(curMax > maxEnd - maxStart){
            maxStart = i - (curMax - 1) / 2;
            maxEnd = i + curMax / 2;
        }
    }
    return s.substring(maxStart,maxEnd+1);
};

var expandOnCenter = function(s, L, R){
    while(L >= 0 && R < s.length && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}