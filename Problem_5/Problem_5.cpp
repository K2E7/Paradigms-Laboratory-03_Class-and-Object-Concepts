#include<iostream>
#include<assert.h>

using namespace std;

namespace GrowingStack{

    static int stack_count = 0;

    class growing_stack{

        public:
            growing_stack(int MaxSize = 3, int Constant = 2, int Upper_Bound = 20);
            growing_stack(const growing_stack &otherstack);

            void push(const int &);
            int  pop(void);
            inline void display();
            inline bool isEmpty();
            inline int  getMaxSize();
            inline int  currentSize();
            inline void print_stack();

            growing_stack operator+(const growing_stack& stack2);


        private:
            void inflate(){

                if(current_size + constant > upper_bound){
                    int *new_data = new int[upper_bound];
                    max_size = upper_bound;
                } else{
                    int *new_data = new int[current_size + constant];
                    for(int i = 0; i<current_size; i++)
                        new_data[i] = data[i];

                    delete(data);
                    data = new_data;
                    max_size += constant;
                }
            }

        protected:
            int   *data;
            int   current_size;
            int   max_size;
            int   constant;
            int   upper_bound;

    };

    growing_stack::growing_stack(int MaxSize, int Constant, int Upper_Bound)
                  : max_size(MaxSize), constant(Constant), upper_bound(Upper_Bound){
        
        data = new int[max_size];
        current_size = 0;

        stack_count++;
    }

    growing_stack::growing_stack(const growing_stack &otherstack){

        this->max_size      = otherstack.max_size;
        this->data          = new int[max_size];
        this->current_size  = otherstack.current_size;
        this->constant      = otherstack.constant;
        this->upper_bound   = otherstack.upper_bound;

        stack_count++;
    }

    growing_stack::growing_stack operator+(const growing_stack& stack2){

        growing_stack sum;

        sum.current_size = this->current_size + stack2.current_size;

        this->upper_bound > stack2.upper_bound ? sum.upper_bound = this->upper_bound 
                                               : sum.upper_bound = stack2.upper_bound;

        this->constant > stack2.constant ? sum.constant = this->constant
                                         : sum.constant = stack2.constant;

        this->max_size > stack2.max_size ? sum.max_size = this->max_size
                                         : sum.max_size = stack2.max_size;

        if(sum.current_size >= sum.upper_bound){
            int temp = sum.upper_bound - sum.current_size;
            sum.upper_bound += (temp*2);
        }

        while(sum.max_size <= sum.current_size)
            sum.max_size += sum.constant;

        sum.data = new int[sum.max_size];
        
        int idx = 0;
        for(int i=0; i<this->current_size; i++){
            sum.data[idx] = this->data[i];
            idx++;
        }
        for(int i=0; i<stack2.current_size; i++){
            sum.data[idx] = stack2.data[i];
            idx++;
        }

        return sum;
    }

    void growing_stack::push(const int &item){

            if(current_size == max_size-1)
                this->inflate();
            
            assert(current_size != upper_bound);

            data[current_size++] = item;
    }

    int growing_stack::pop(void){
        
        assert(current_size > 0);
        return data[--current_size];
    }

    inline void growing_stack::display(){

        cout<<"\ncurrent size : "<<this->current_size<<endl;
        cout<<"max size : "<<this->max_size<<endl;
        cout<<"upper bound : "<<this->upper_bound<<endl;

    }

    inline bool growing_stack::isEmpty(){

        if(this->current_size == 0)
            return true;
        else
            return false;  
    }

    inline void growing_stack::print_stack(){

        cout<<endl;
        for(int i=0; i<current_size; i++)
            cout<<data[i]<<" ";
        cout<<endl<<endl;
    }

    inline int growing_stack::getMaxSize(){
        return max_size;
    }

    inline int growing_stack::currentSize(){
        return current_size;
    }


                       
}

using namespace GrowingStack;
growing_stack alt_merge(growing_stack &x, growing_stack &y){

    growing_stack z;

    while(!x.isEmpty() && !y.isEmpty()){

        int t1,t2;
        t1 = x.pop();
        z.push(t1);
        t2 = y.pop();
        z.push(t2);
    }
    if(x.isEmpty() && y.isEmpty())
        return z;

    if(x.isEmpty()){

        while(!y.isEmpty()){

            int temp1;
            temp1 = y.pop();
            z.push(temp1);
        }
        if(x.isEmpty() && y.isEmpty())
            return z;
    }

    else if(y.isEmpty()){

        while(!x.isEmpty()){

            int temp1;
            temp1 = x.pop();
            z.push(temp1);
        }
        if(x.isEmpty() &&  y.isEmpty())
            return z;
    }
    return z;
}

int main()
{
    cout<<endl;
    growing_stack G1(1);//demonstrated parameterized constructor
    growing_stack G2(G1); // demonstrated copy constructor
    growing_stack G0 = G1;

    growing_stack G3(1);//demonstrated default constructor

    G1.push(3);
    G1.push(1);
    G1.push(4);
    G1.push(1);
    G1.push(5);
    //cout<<"current size of G1: "<<G1.currentSize()<<endl;
    //cout<<"max size of G1: "<<G1.getMaxSize()<<endl;
    cout<<"G1_____________";
    G1.display();
    G1.print_stack();

    G2.push(9);
    G2.push(2);
    G2.push(6);
    G2.push(5);
    //cout<<"current size of G2: "<<G2.currentSize()<<endl;
    //cout<<"max size of G2: "<<G2.getMaxSize()<<endl;
    cout<<"G2_____________";
    G2.display();
    G2.print_stack();

    G3 = alt_merge(G1, G2);
    cout<<"G3_____________";
    G3.display();
    G3.print_stack();

    G0 = G3;//demonstrated that content can be updated using =
    cout<<"G0_____________";
    G0.display();
    G0.print_stack();

    growing_stack G_Sum = G1 + G2;
    G_Sum.display();
    G_Sum.print_stack();
    
    return 0;
}   