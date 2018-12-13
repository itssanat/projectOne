// sieve function to generate Prime number // 
  /// let assume we have to generate prime number less than n //

bool isPrime[n];

void sieve(){
    for(int i  = 0;i<n;i++)
    	isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;
    
    for(int i=2;i*i<n;i++){
        if(isPrime[i]){
            for(int j = i*i;j<n;j = j+i)
            isPrime[j] = false;
        }
    }
 }