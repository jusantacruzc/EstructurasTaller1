// made by Esteban Santacruz (https://github.com/Jestebansamt)

#include <bits/stdc++.h>

using namespace std;


template <typename T>

class Stack {
private:
    int top;
    int size;
    T* tArray;

public:

    Stack(int n) : top(0), size(n) ,tArray(new T[n]) {}

    ~Stack() {
        delete[] tArray; 
    }

    T geTop(){
        return tArray[top-1];
    }

    bool empty() const {
        return top <= 0;
    }

    bool full() const {
        return top >= size;
    }

    T pop() {
        if (empty())
            throw runtime_error("Stack is empty");
        top--;
        return tArray[top];
    }

    void push(T item) {
        if (full())
            throw runtime_error("Stack is full");
        tArray[top] = item;
        top++;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    string vec[n];
    int grid[n][m] ;
    for(auto&a: vec) cin >> a;

    for(int i = 0; i <m; ++i){
        int cc = 1;
        for(int j = 0; j < n; ++j){
            
            if(vec[j][i] == '.'){
                grid[j][i] = cc;
                cc++;
            }else{
                grid[j][i] = 0;
                cc = 1;
            }
        }
    }

    int ans = 0;
    for(auto&vec:grid){
       
        Stack<pair<int,int>> s(m);
        int cans = 0;

        for(int i = 1; i <= m; ++i){
            pair<int, int> cp;
            cp.first = vec[i-1];
            cp.second = i-1;
            if(i == 1 ){
                s.push(cp);
                continue;
            }
            while(!s.empty() && s.geTop().first > vec[i-1]){
                cp.second = s.geTop().second;
                cans = max(cans, (s.geTop().first * abs((s.geTop().second+1-i))));
                s.pop();
            }
            s.push(cp);
        }

        while(!s.empty()){
            cans = max(cans, s.geTop().first * (m - s.geTop().second));
            s.pop();
        }
        ans = max(cans,ans);
    }
    cout << ans << " ";

    return 0;
}
