#include<iostream>
#include<assert.h>

using namespace std;

typedef struct hello{
    int a;
    int b;
    char c;
} world;

namespace GrowingStack{
    template <typename generic_type>
    class growing_stack{

        public:
            growing_stack(int MaxSize = 3, int Constant = 2, int Upper_Bound = 20);
            growing_stack(const growing_stack<generic_type> &otherstack);

            inline void         push(const generic_type &item);
            inline void         display();
            inline bool         isEmpty();
            inline generic_type pop(void);

            void print_stack();
            void print_struct_stack();

        private:
            void inflate(){

                if(current_size + constant > upper_bound){
                    generic_type *new_data = new generic_type[upper_bound];
                    max_size = upper_bound;
                } else{
                    generic_type *new_data = new generic_type[current_size + constant];
                    for(int i = 0; i<current_size; i++)
                        new_data[i] = data[i];

                    delete(data);
                    data = new_data;
                    max_size += constant;
                }
            }

        protected:
            generic_type    *data;
            int             current_size;
            int             max_size;
            const int       constant;
            const int       upper_bound;

    };

    template <class generic_type>
    growing_stack<generic_type>::growing_stack(int MaxSize, int Constant, int Upper_Bound)
                                : max_size(MaxSize), constant(Constant), upper_bound(Upper_Bound){
        
        data = new generic_type[max_size];
        current_size = 0;
    }

    template <typename generic_type>
    growing_stack<generic_type>::growing_stack(const growing_stack<generic_type> &otherstack)
                                :data(otherstack.data),current_size(otherstack.current_size),max_size(otherstack.max_size),
                                 constant(otherstack.constant),upper_bound(otherstack.upper_bound){}

    template <class generic_type>
    inline void growing_stack<generic_type>::push(const generic_type &item){

            if(current_size == max_size-1)
                this->inflate();
            
            assert(current_size != upper_bound);

            data[current_size++] = item;
    }

    template <typename generic_type>
    inline generic_type growing_stack<generic_type>::pop(void){
        
        assert(current_size > 0);
        return data[--current_size];
    }

    template <class generic_type>
    inline void growing_stack<generic_type>::display(){

        cout<<"\ncurrent size : "<<this->current_size<<endl;
        cout<<"max size : "<<this->max_size<<endl;
        cout<<"upper bound : "<<this->upper_bound<<endl;
    }

    template <typename generic_type>
    inline bool growing_stack<generic_type>::isEmpty(){

        if(this->current_size == 0)
            return true;
        else
            return false;  
    }

    template<typename generic_type>
    void growing_stack<generic_type>::print_stack(){

        cout<<endl;
        for(int i=0; i<current_size; i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }

    template<typename generic_type>
    void growing_stack<generic_type>::print_struct_stack(){

        growing_stack<world> y = *this;

        cout<<endl;
        cout<<"----------------------"<<endl;
        for(int i=0; i<current_size; i++){
            world temp = y.pop();
            cout<<"a : "<<temp.a<<" | b : "<<temp.b<<" | c : "<<temp.c<<endl;
            cout<<"----------------------"<<endl;
        }
    }
}

using namespace GrowingStack;
int main()
{
    growing_stack<int> GI;
    //demonstrating integer Growing_Stack
    cout<<"\nint Growing Stack.../"<<endl;
    GI.push(1);
    GI.push(6);
    GI.push(1);
    GI.push(8);
    GI.push(0);
    GI.push(3);
    GI.push(3);
    GI.pop();
    GI.display();
    GI.print_stack();

    growing_stack<short> GS; 

    //demonstrating short Growing_Stack
    cout<<"\nshort Growing Stack.../"<<endl;
    GS.push(-23);
    GS.push(-21);
    GS.push(123);
    GS.push(872);
    GS.push(-89);
    GS.push(-45);
    GS.pop();
    GS.display();
    GS.print_stack();

    growing_stack<float> GF;

    //demonstrating float Growing_Stack
    cout<<"\nfloat Growing Stack.../"<<endl;
    GF.push(-34.22);
    GF.push(-9.332);
    GF.push(453.22);
    GF.push(44.22);
    GF.push(5);
    GF.push(3.14);
    GF.display();
    GF.print_stack();

    growing_stack<double> GD;

    //demonstrating long Growing_Stack
    cout<<"\ndouble Growing Stack.../"<<endl;
    GD.push(-3145.96);
    GD.push(161.803);
    GD.push(87939.22);
    GD.push(7.843);
    GD.push(-2020.04);
    GD.push(848.3690);
    GD.pop();
    GD.display();
    GD.print_stack();

    growing_stack<world> Gs;

    cout<<"\nstruct Growing Stack.../"<<endl;
    world s1;
    s1.a = 7;
    s1.b = 8;
    s1.c = 'a';
    Gs.push(s1);

    world s2;
    s2.a = 3;
    s2.b = 1;
    s2.c = 'p';
    Gs.push(s2);

    world s3;
    s3.a = 1;
    s3.b = 6;
    s3.c = 'g';
    Gs.push(s3);
    Gs.print_struct_stack();
}   
