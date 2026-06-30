// Last updated: 30/06/2026, 19:34:27
/* we will use 2 queues [] []
    basically to make queue behave like a stack if we have [1,2,3] in
    the queue it will pop 1 to behave like stack we want it to pop 3
    but we have to use queues only so we will have to use the reverse
    order of elts ie [3,2,1] so when we pop we will get 3 remember
    queue is like a ticket counter where the queue at a counter where
    the counter is in the left end so the person who has bought the
    tickets will leave
   consider the 2nd elt=2 for ease of understand assuming we already
   inserted the first elt=1
   it will look like [1] [2]
   now to reverse the order of elt of q1 into q2
   it will look like [] [2,1]
   now move the reversed elts back into q1 so that it contains
   reversed elts
   it will look like [2,1] []
   now add the 3rd elt=3 into q2
   it will look like [2,1] [3]
   now push elts of q1 from the front using .front into q2
   it will look like [] [3,2,1]
   now move reversed q2 into q1 so that it contains reversed elts
   it will look like [3,2,1] []
   
   implies the logic is moving new elt into q2 then moving all elts
   of q1 into q2 starting from the front so we get the elts in
   reversed order and then move them back into q1 so that it contains
   the final reversed numbers
*/
class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1,q2;
    void push(int x) {
        // push elts into q2
       q2.push(x);
       
       //push elts of q1 into q2 starting from the front
       while(!q1.empty()){
           q2.push(q1.front());
           q1.pop();
       }
       
       swap(q1,q2);
    }
    
    int pop() {
        int ans=q1.front();     
/*we can't use q1.pop() because .pop() does not return any value othwerise if .pop() would be   returning a value we would willingly do that becuase our elts are [1,2,3] to behave like  a stack we want pop to give us 3 but we need to use queues where opp gives us the front elt so our modified arrray that we are considereing throughout the problem which is q1 is [3,2,1] so now pop gives us 3 becuase we are doing q1.pop() queue pops from the front. so if q1.pop( had reurnde a value we would just return that for pop function here but .pop() dosen't return anythign so we have to use .front() on q1 */
      q1.pop();
      return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */