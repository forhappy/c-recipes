stack<int> s;
void push(int elem)
 {
    if (s.empty()) {
        s.push(elem);
        s.push(elem);
    } else {
        int min = s.top();
        s.pop();
        s.push(elem - min);
        s.push(elem < min ? elem : min);
    }
}

int pop()
{
    int min = s.top();
    s.pop();
    int diff = s.top();
    s.pop();
    if (diff < 0) {
        s.push(min - diff);
        return min;
    } else {
        if (!s.empty()) {
            s.push(min);
            return diff + min;
        }
        return min;
    }
}

int min()
{
    int min = s.top();
    return min;
}
