// Last updated: 30/06/2026, 19:34:18
// here we don't need one by one first addign elt into q2 then moving from q1 into q2 and all that just take all elts and then pop and push into s2 becuase this time we have stack and it gives us the pattern we want in the case of queue it didn't work out becuase the pattern of pop and push did not give use the required correct order of numbers.

// but we use the reversal only when we need to pop not everytime we push

// Transfer elements from s1 to s2 only when s2 is empty.This ensures that the oldest element is always popped first 
// example-
/*Step 1
push(1)
push(2)
push(3)
s1 = [1,2,3]
s2 = []

Step 2
popElement()
Transfer:
s1 → s2
s1 = []
s2 = [3,2,1]

Pop:
pop → 1

Correct.

Step 3
Now:
push(4)
s1 = [4]
s2 = [3,2]       hence we need  s1.empty() && s2.empty (to say whether or not the queue is
                 empty or not)

Step 4
Now your popElement() runs:
move s1 → s2
s2 = [3,2,4]
Top becomes 4, so pop gives 4 ❌
But queue should return 2.
So the queue order breaks.

Correct rule
We only transfer when s2 is empty.
This keeps old elements in correct order.*/

class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1,s2;

    void push(int x) {
         // push into s1
        s1.push(x);
        // // pop and push into s2 
        // while(!s1.empty()){
        //     int elt=s1.back();
        //     s1.pop();
        //     s2.push(elt);
        // }
    }
    
    int pop() {
         if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        }
        int ans=s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        // int ans=s2.back();
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        // int ans=s2.top();
        // // s2.pop();
        return s2.top();
    }
    
    bool empty() {
       return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */