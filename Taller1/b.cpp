#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Queue {
private:
    int top;
    int rear;
    int size;
    int currentSize;
    T* tArray;

public:

    Queue(int n) : top(0), currentSize(0), rear(0), size(n) ,tArray(new T[n]) {}

    bool empty() const {
        return currentSize <= 0;
    }

    bool full() const {
        return currentSize >= size;
    }

    T pop() {
        if (empty())
            throw runtime_error("Queue is empty");
        top++;
        currentSize--;
        return tArray[(top - 1) % size];
    }

    void push(T item) {
        if (full())
            throw runtime_error("Queue is full");
        tArray[rear % size] = item;
        currentSize++;
        rear++;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int targetValue = 0, maxValue = 0, big = 0, index=0, ans = 0, vec[10] = {0};
        Queue<int> q(n);

        for(int i = 0; i <n; ++i){
            int a; cin >> a;
            if(i == m) targetValue = a;
            maxValue = max(a, maxValue);
            vec[a]++;
            q.push(a);
        }

        int i = 9, ni=0;
        while(true){
            while(vec[i] == 0) i--;
            if(i <= targetValue) break;
            int num = q.pop();
            q.push(num);
            if(num == i){
                vec[i]--;
                big++;
                if(vec[i] == 0) index = ni%n;
            }
            ni++;
        }

        if(targetValue != maxValue){
            while(true){
                int num = q.pop();
                q.push(num);
                index++;
                index%=n;
                if(num == targetValue) ans++;
                if(index == m)break;  
            }
            cout << (ans+big == 0 ? 1 : ans+big) << "\n";
        }else{
            for(int i = 0; i <= m; ++i){
                int num = q.pop();
                q.push(num);
                if(num == targetValue) ans++;
            } 
            cout << ans << "\n";
        }
    }
    return 0;
}