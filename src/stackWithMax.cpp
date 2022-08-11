#include <stack>
#include <unordered_map>
#include <cassert>
#include <iostream>

class Stack{
    std::stack<int> fStack;
    std::unordered_map<int, std::stack<int>> maxPerNum;
    public:
    int max()
    {
        assert(!fStack.empty());
        int top = fStack.top();
        auto maxIt = maxPerNum.find(top);
        assert(maxIt != maxPerNum.end());
        assert(!maxIt->second.empty());
        return maxIt->second.top();
    }
    void push(int val){
        
        int maxToPush = val;
        if (!fStack.empty()){            
            int currentMax = max();
            if (val < currentMax){
                maxToPush = currentMax;
            }
        }      
        maxPerNum[val].push(maxToPush);

        fStack.push(val);
    }

    int pop()
    {
        assert(!fStack.empty());
        int top = fStack.top();
        fStack.pop();
        maxPerNum[top].pop();
        return top;
    }

    
};

int main()
{
    Stack s;
    s.push(1);
    std::cout << "Max: " << s.max() << std::endl;
    s.push(9);
    std::cout << "Max: " << s.max() << std::endl;
    s.push(8);
    std::cout << "Max: " << s.max() << std::endl;
    s.push(10);
    std::cout << "Max: " << s.max() << std::endl;
    s.push(19);
    std::cout << "Max: " << s.max() << std::endl;
    std::cout << "Top: " << s.pop();
    std::cout << "Max: " << s.max() << std::endl;
    std::cout << "Top: " << s.pop();
    std::cout << "Max: " << s.max() << std::endl;
    std::cout << "Top: " << s.pop();
    std::cout << "Max: " << s.max() << std::endl;
    std::cout << "Top: " << s.pop();
    std::cout << "Max: " << s.max() << std::endl;
}