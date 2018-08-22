/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    solutions = [];
    permutateHelper(nums,[])
    return solutions;
}

let solutions = []

let permutateHelper = (s, chosen) =>{
    if(s.length === 0)
        solutions.push([...chosen]);
    else{
      for(let i = 0; i < s.length; i ++)
      {
          //pull out a character from s
          let ch = s[i];
          s.splice(i, 1);
          //add that character to chosen
          chosen.push(ch);
          //call permutateHelper again
          permutateHelper(s, chosen);
        
          //return the item to s
          s.splice(i,0,ch);
          //remove the item from chosen
          chosen.splice(chosen.length-1,1);
        
      }
    }
}
