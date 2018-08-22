var isValid = function(s) {
    var parens = {'(':')',
                  '{':'}',
                  '[':']'}
  
    let stack = [];
      
    for(let i = 0; i < s.length; i ++)
    {
      if(parens[s[i]])
        stack.push(parens[s[i]])
        else if(stack.pop() != s[i])
          return false;
    }
  
    if(stack.length != 0)
      return false;
    else
      return true;
  };