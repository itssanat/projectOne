/* Dynamic Programming implementation of LCS problem */
// TC is n^2  // 
#include<bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2) 
{
    int m = str1.size();
    int n = str2.size();
    int arr[m+1][n+1]; 

    /* Following steps build arr[m+1][n+1] in bottom up fashion. Note  
    that arr[i][j] contains length of LCS of str1[0..i-1] and str2[0..j-1] */
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        {
            if (i == 0 || j == 0) 
                arr[i][j] = 0; 
            else if (str1[i-1] == str2[j-1]) 
                arr[i][j] = arr[i-1][j-1] + 1; 
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]); 
        } 
    }
    /* arr[m][n] contains length of LCS for str1[0..n-1] and str2[0..m-1] */
    return arr[m][n]; 
} 
   
int main() 
{ 
    string str1,str2; 
    cin>>str1>>str2;
    cout<<LCS(str1,str2)<<endl;
    return 0; 
} 