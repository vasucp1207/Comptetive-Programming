#include<bits/stdc++.h>

using namespace std;

class SegmentTree{
    private:
        vector<int> st, a;
        int n;
        int left(int p){ return p << 1; }
        int right(int p){ return (p << 1) + 1; }

        void build(int p, int L, int R){
            if(L == R) st[p] = L;          // store the index
            else{
                build(left(p), L, (L + R) / 2);
                build(right(p), (L + R) / 2 + 1, R);
                
                // recalculation
                int p1 = st[left(p)];
                int p2 = st[right(p)];
                st[p] = (a[p1] <= a[p2])? p1: p2;      // storing the min index
            }                
        }

        int rmq(int p, int L, int R, int i, int j){
            if(i > R || j < L) return -1;      // current segment is outside the query
            if(i <= L && j >= R) return st[p];   // inside the range     
            
            int p1 = rmq(left(p), L, (L + R) / 2, i, j);
            int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

            if(p1 == -1) return p2;           // if segment outside the query
            if(p2 == -1) return p1;            
            return (a[p1] <= a[p2])? p1: p2;
        }

        void update(int p, int L, int R, int x, int y){
            if(L == R) return ;
            else{
                int mid = (L + R) / 2;
                if(x <= mid)
                    update(left(p), L, mid, x, y);
                else
                    update(right(p), mid + 1, R, x, y);

                int p1 = st[left(p)];
                int p2 = st[right(p)];
                st[p] = (a[p1] <= a[p2])? p1: p2;
            }
        }

    public:
        SegmentTree(const vector<int> &_a){
            a = _a;
            n = (int)a.size();
            st.assign(4 * n, 0);
            build(1, 0, n - 1);
        }
        
        int rmq(int i, int j){
            return rmq(1, 0, n - 1, i, j);
        }

        void update(int x, int y){
            a[x] = y;
            return update(1, 0, n - 1, x, y);
        }
};

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); 

    int arr[] = {18, 17, 13, 19, 15, 11, 20};
    vector<int> a(arr, arr + 7);
    SegmentTree st(a);

    cout << (st.rmq(1, 3)) << endl;     // index = 2
    cout << (st.rmq(4, 6)) << endl;     // index = 5                            

    st.update(2, 20);
    st.update(5, 21);
    st.update(0, 8);

    cout << st.rmq(0, 3) << endl;       // 0
    cout << st.rmq(1, 3) << endl;       // 1
    cout << st.rmq(4, 6) << endl;       // 4    


    return 0;    
}
