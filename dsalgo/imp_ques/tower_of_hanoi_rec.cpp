long long toh(int N, int from, int to, int aux) {
    
    if(N < 1) {
        return 0;
    }
    
    long long moves = (1 << N) - 1;

    //move top N-1 disks from [FROM] to [AUX] using [TO]
    toh(N-1, from, aux, to);
    
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    
    //move top N-1 disks from [AUX] to [TO] using [FROM]
    toh(N-1, aux, to, from);
    
    return moves;
}
