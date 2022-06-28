bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(const auto &c : expression){
        switch (c){
            case '{': s.push('}');break;
            case '[': s.push(']');break;
            case '(': s.push(')');break;
            default :
                if(s.size()==0 || c != s.top()) return false;
                else s.pop();
        }
    }
    return s.size()==0;
}