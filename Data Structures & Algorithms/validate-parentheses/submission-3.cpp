class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)
        {
            return false;
        }

        std::stack<char> bStack;

        for (char c : s)
        {
            if(c == '(' or c =='{' or c == '[')
            {
                bStack.push(c);
            }
            else 
            {
                if (bStack.empty())
                {
                    return false;
                }

                switch(c)
                {
                    case ')':{
                        if(bStack.top() != '(')
                        {
                            return false;
                        }
                        break;
                    }
                    case ']':{
                        if(bStack.top() != '[')
                        {
                            return false;
                        }
                        break;
                    }
                    case '}':{
                        if(bStack.top() != '{')
                        {
                            return false;
                        }
                        break;
                    }
                }
                bStack.pop();
            }
        }

        if (not bStack.empty())
        {
            return false;
        }

        return true;
    }
};
