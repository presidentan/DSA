/*
    Ho va ten: Ngo Dinh Ngoc An
    Lop: CNTT3_K66
    MSV: 251210795
*/
#include <iostream>   
#include <utility> 
using namespace std;

int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool vis[1009][1009];

template <class T>
class Queue{
    private:
        struct Node{
        T data;
        Node* next;

        Node (T val){
            data = val;
            next = nullptr;
            }
        };
        Node* frontNode;
        Node* backNode;
        int count;
    public:
        Queue(){
            frontNode = nullptr;
            backNode = nullptr;
            count = 0; 
        }

        ~Queue() { while (!empty()) pop(); }

        int size(){
            return count;
        }

        bool empty(){
            return frontNode == nullptr;
        }

        void push(T val){
            Node* newNode = new Node(val);
            if (empty()){
                frontNode = backNode = newNode;
            }
            else{
                backNode->next = newNode;
                backNode = newNode;
            }
            count++;
        }
        
        void pop(){
            if (empty()) {
                return;
            }
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (frontNode == nullptr) {
                backNode = nullptr;
            }
            delete temp;
            count--;
        }
        T& front(){
            return frontNode -> data;
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    pair <int, int> a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    Queue<pair<int,int>> q;
    Queue<int> pos;
    q.push(a);
    pos.push(0);    
    pair<int,int> t;
    int p;
    while (!q.empty()){
        t = q.front();
        p = pos.front();
        q.pop();
        pos.pop();
        //cout << t.first << ' ' << t.second << ' ' << p << '\n';
        if (t == b){
            cout << p;
            return 0;
        }
        if (t.first > n || t.first < 1 || t.second > m || t.second < 1){
            continue;
        }
        if (vis[t.first][t.second]){
            continue;
        }
        vis[t.first][t.second] = true;
        for (int i = 0; i < 8; i++){
            q.push({t.first + x[i], t.second + y[i]});
            pos.push(p + 1);
        }
    }       
    cout << -1;
    return 0;
}