class Solution {
public:
    bool isOp(const std::string& token)
    {
        if (token == "+" or token == "-" or token == "*" or token == "/")
        {
            return true;
        }

        return false;
    }

    int evalOp(const std::string& token, int arg1, int arg2)
    {
        if(token == "+")
        {
            return arg1 + arg2;
        }

        if(token == "-")
        {
            return arg1 - arg2;
        }

        if(token == "*")
        {
            return arg1 * arg2;
        }

        if(token == "/")
        {
            return arg1 / arg2;
        }

        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        std::stack<int> evalStack;

        for(const auto& token : tokens)
        {
            if(isOp(token))
            {
                int arg2 = evalStack.top();
                evalStack.pop();

                int arg1 = evalStack.top();
                evalStack.pop();

                evalStack.push(evalOp(token, arg1, arg2));
            }
            else
            {
                evalStack.push(std::stoi(token));
            }
        } 

        return evalStack.top();
    }
};
