/*The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/* This is very difficult question with a solution which is completely
non-intuitive*/

/* Approach:1. Define a variable minEle that stores the current minimum element in the stack. 
When a minEle is removed fromt he stack, we push “2x – minEle” into the stack instead
of x so that previous minimum element can be retrieved using current minEle and its value stored in stack.

Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.
Pop() : Removes an element from top of stack.

Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), update (minEle = 2*minEle – y). Now retrieve previous minimum from current minimum and its value in stack.*/

/*returns min element from stack*/
int _stack :: getMin()
{   
    if(s.empty())
        return -1;
    return minEle;
   //Your code here
}

/*returns poped element from stack*/
int _stack ::pop()
{   
    if(s.empty())
        return -1;
    int y=s.top();
    s.pop();
    if(y>=minEle)
        return y;
    else
        {
            minEle=2*minEle-y;
            return (minEle+y)/2;
        }
    
   //Your code here
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty())
        {
            s.push(x);
            minEle=x;
        }
    else if(x>=minEle)
        {
            s.push(x);
            
        }
    else 
        {
            s.push(2*x-minEle);
            minEle=x;
        }
   //Your code here
}