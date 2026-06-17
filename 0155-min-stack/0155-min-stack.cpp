// class MinStack {
//     vector<int> stack;   // because vector as a stack allows random access
// public:
//     MinStack() {}
    
//     void push(int val) {
//         stack.push_back(val);        
//     }
    
//     void pop() {
//         stack.pop_back();
//     }
    
//     int top() {
//         return stack.back();   // push_back(10); push_back(20); push_back(30); vector: [10,20,30] 
//                         // the last elt is the most recently added, and hence at the top
//     }
    
//     // BRUTE FORCE
//     // getMin is not o(1)
//     int getMin() {
//         int minVal=stack[0];
//         for(int a:stack){
//             minVal=min(a,minVal);
//         }
//         return minVal;
//     }
// };

class MinStack {
    vector<int> stack;   // because vector as a stack allows random access
    vector<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty()){
            minStack.push_back(val);
        }
        else{
            minStack.push_back(min(val,minStack.back()));
        }        
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();   // push_back(10); push_back(20); push_back(30); vector: [10,20,30] 
                        // the last elt is the most recently added, and hence at the top
    }
    
    int getMin() {
        return minStack.back();
    }
};