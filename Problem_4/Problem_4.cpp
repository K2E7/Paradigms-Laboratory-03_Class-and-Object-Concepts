#include<iostream>
#include<ctime>

using namespace std;

    
    class node{

        int  key;
        node *next;

        node();
        node(int x);

        friend class circular_list;
    };

    node::node(){
        
        next = NULL;
    }
    node::node(int x){

        key  = x;
        next = NULL;
    }

    class circular_list{
        public:
            circular_list(int initial_key){
                
                node *first_node = new node(initial_key);

                this->root = first_node;
                this->root->next = root;

                this->no_of_nodes = 1;
            }

            void pushback(int new_key){

                node *new_node = new node(new_key);

                new_node->next = this->root->next;
                this->root->next = new_node;
                this->root = new_node;
                
                this->no_of_nodes++;
            
            }

            void erasenode(int k){

                if(root == NULL)    return;

                if(root->key == k && root->next == root){

                    delete(root);
                    root = NULL;
                    no_of_nodes--;
                    return;
                }

                node *temp = root, *del;

                if(root->key == k){

                    node *temp = root;
                    node *first_node = root;

                    while(temp->next != root){
                        temp = temp->next;
                    }

                    root = root->next;
                    temp->next = root;
                    delete(first_node);

                    no_of_nodes--;
                    return;
                }

                while(temp->next != root && temp->next->key != k)
                    temp = temp->next;

                if(temp->next->key == k){

                    del = temp->next;
                    temp->next = del->next;
                    delete(del);
                    no_of_nodes--;
                    return;
                }
            }

            void printlist(){

                node *print;
                if(root == NULL){
                    std::cout<<"The List is Empty"<<endl;
                    return;
                }

                print = root->next;
                std::cout<<endl;
                do{
                    cout<<print->key<<" ";
                    print = print->next;
                }while(print != root->next);
            }

            int getsize()
            {
                return no_of_nodes;
            }

            int getkey()
            {
                return root->key;
            }
        protected:
            node *root;
            int   no_of_nodes;
    };

    void deleteElement(int arr[], int &n, int x)
    {

        int i;
        for (i=0; i<n; i++)
        if (arr[i] == x)
            break;
 
        if (i < n){
            n--;
            for(int j=i; j<n; j++)
                arr[j] = arr[j+1];
        }
    }

    int continuous_traversal(int *arr, int size, int start){
        
        srand(time(0));
        int skip = 1+rand()%(size*2);
        int idx = ((skip)%size + start)%size;
        
        //cout<<"to_del : "<<arr[idx]<<endl;

        return arr[idx];
    }
     
    void printarray(int *arr, int size){
        cout<<endl;
        cout<<"array : ";
        for(int k=0; k<size; k++)
            cout<<arr[k]<<" ";
    }
 

    int game(int total, int person_no){
        
        circular_list game_c(1);
        for(int q=2; q<=total; q++){

            game_c.pushback(q);
        }

        int *sample_arr = new int[game_c.getsize()];
        int size_of_arr = game_c.getsize();
        for(int j=0; j<size_of_arr; j++)
            sample_arr[j] = j+1;

        while(game_c.getsize() != 1){
            
            int to_del_key = continuous_traversal(sample_arr, size_of_arr, person_no);
            game_c.erasenode(to_del_key);
            deleteElement(sample_arr, size_of_arr, to_del_key);
            //printarray(sample_arr, size_of_arr);
            //cout<<endl;
            game_c.printlist();
            //cout<<" size: "<<game_c.getsize();
            
        }
        int winner = game_c.getkey();

        cout<<endl;
        return winner;
    }


int main(){
    //std::cout<<test.getsize()<<endl;
    
    int p = 1 + rand()%(7);
    int w = game(7, p);
    cout<<"\nThe winner is "<<w<<endl;

    //cout<<"\n"<<s<<"    "<<p;
    return 0;
}
