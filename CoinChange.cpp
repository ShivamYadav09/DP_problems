/*
    Coin Change problem --> https://www.geeksforgeeks.org/coin-change-dp-7/
    Space --> O(n) ; Timee --> O(n2)
*/


#include<bits/stdc++.h>

using namespace std;

int count( int S[], int m, int n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            //seeing if the difference is less than 0 to reduce the number of lookups; not in GFG :)
            if(j-S[i]>=0)
            	table[j] += table[j-S[i]]; 
            else
            	continue;
  
    return table[n]; 
}
int main(){
	int arr[] = {2, 5, 3, 6}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 10; 
    cout << count(arr, m, n); 
    return 0;
}