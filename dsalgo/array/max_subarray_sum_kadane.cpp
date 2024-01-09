long long maxSubarraySum(vector<int> arr, int n)
{
    long long ans = 0;

    long long sumTillNow = 0;

    for(int i = 0 ; i < n ; i++) {

        long long element = (long long)arr[i];

        sumTillNow = sumTillNow + element;

        ans = max(ans, sumTillNow);

        if(sumTillNow < 0) {

            sumTillNow = 0;
        }
    }

    return ans;
}