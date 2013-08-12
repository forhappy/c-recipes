bool isValid(std::string s) {
    if (s.empty() || s.size() == 1) return false;

    std::stack<char> aux;
    aux.push('x'); // push a dummy char first.
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        if ((aux.top() == '(' && *it == ')')
                || (aux.top() == '[' && *it == ']')
                || (aux.top() == '{' && *it == '}')) {
            aux.pop();
        } else aux.push(*it);
    }
    aux.pop(); // pop up the dummy char.
    return aux.empty();
}
