void moveDisk(vector< stack<int> > & stk, int rod1, int rod2) {
    if((stk[rod2].empty()) || (!stk[rod1].empty() && (stk[rod1].top() < stk[rod2].top()))) {
        cout << "move disk " << stk[rod1].top() << " from rod " << rod1 + 1 << " to rod " << rod2 + 1 << endl;
        stk[rod2].push(stk[rod1].top());
        stk[rod1].pop();
    } else {
        moveDisk(stk, rod2, rod1);
    } 
}

// avoid space at the starting of the string in "move disk....."
long long toh(int N, int from, int to, int aux) {
    if(N < 1) {
        return 0;
    }
    long long moves = (1 << N) - 1;
    
    if(N % 2 == 0) {
        swap(to, aux);
    }
    
    from--;
    to--;
    aux--;
    
    vector< stack<int> > stk(3);
    
    for(int i = N ; i >= 1 ; i--) {
        stk[from].push(i);
    }
    
    for(int i = 1 ; i <= moves ; i++) {
        if(i%3 == 1) {
            moveDisk(stk, from, to);
        } else if(i%3 == 2) {
            moveDisk(stk, from, aux);
        } else {
            moveDisk(stk, aux, to);
        }
    }
    return moves;
}