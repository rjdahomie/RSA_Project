#include <iostream>
#include <cmath>
#include<vector>
#include<unordered_map>
 
//Checks whether the given value is prime. 
bool IsPrime(int n)
{
	for(int i = 2; i<= n/2; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
 
	return true;
}
 
//Generates the first sqrt(n) primes in a vector, which we will use to check for p * q = n
std::vector<int> PrimesToCheck(int count)
{
	std::vector<int> primes;
	
		int i = 2;
	
	int numberOfCheckedPrimes = 0;
    while(numberOfCheckedPrimes < count)
    {
    	if(IsPrime(i))
    	{
    		primes.push_back(i);
			numberOfCheckedPrimes++;
		}
		i++;
	}
	
	return primes;
}
 
//Find the values of P and Q 
void FindPQ(int & p, int & q, int n, std::vector<int>primes)
{
	int l = 0;
	int r = primes.size() - 1;
	while(l<r){
		if(primes[l] * primes[r] == n){
			p = primes[l];
			q = primes[r];
			break;
		} else if(primes[l] * primes[r] < n){
			l++;
		} else {
			r--;
		}
	}
}
 
int CalculatePhi(int p, int q)
{
	int phi = 0;
	phi = (p - 1) * (q - 1);
	return phi;
}
 
int CalculateDecryptionKey(int e, int phi)
{
 	float d = 0;
 	//We are assuming that the multiple for k is NOT 0.
	int k = 1;
	
	do{
		//Not sure why, but it is making me explicitly cast these integer values to floating point numbers
		//so that d is properly calculated as a decimal / floating point number
		d = (float)((1 + (float)k * (float)phi) / (float)e);
		k++;
		
		//Uncomment the following line if you want to verify the checks being done.
		//std::cout << d << std::endl;
	}while(ceil(d) != d); //Checks if it is an integer
	
	return (int)d;
}
 
int DecryptInteger(int encryptedInteger, int d, int n){
	int result = 1;
	if (1 & d)         
	{
		result = encryptedInteger;
    	while (1) { 
        	if (!d) break;     
    		d >>= 1;         
			encryptedInteger = (encryptedInteger * encryptedInteger) % n;     
    		if (d & 1){
				result = (result * encryptedInteger) % n; 
    		}
		}
	}
	return result;
}
 
char OutputFromInt(int value)
{
	switch(value)
	{
		case 29:
			return ' ';
			break;
		case 30:
			return L'"';
			break;
		case 31: 
			return '.';
			break;
		case 32:
			return ',';
			break;
		case 33:
			return (char)39;		
		default:
			return (char)(value + 62);
			break;
	}
}
 
int gcd(int a, int b){
	if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
 
int main()
{
	int n = 0;
	int p = 0;
	int q = 0;
	//encryption exponent
	int e = 0;
	//decryption key
	int d = 0;
	//length of the encoded message
	int m = 0; 
	int phi = 0;
 
	//std::cout << "Enter a prime number:\n";
	std::cin >> e;
	//std::cout << "Enter the encryption exponent (e):\n";
	std::cin >> n;
	//length of the encoded message.
	std::cin >> m;	
	//std::cout << "Enter some values to decrypt:\n";
	int input = 0;
	std::vector<int> inputs;
	while(m > 0)
	{
		std::cin >> input;
		inputs.push_back(input);
		m--;
	}
	int temperary = round(n/2 + 1);
	std::vector<int> primes = PrimesToCheck(temperary);
	FindPQ(p,q, n, primes);
	phi = CalculatePhi(p,q);
	if((gcd(e, phi) != 1) || !(1 <= e && e < n) || !(IsPrime(p) && IsPrime(q)) || (p==q)){
		std::cout << "Public key not valid!" << std::endl;
		exit(0);
		/*
		if((gcd(e, phi) != 1)){
			std::cout << e << " " << phi << " " << gcd(e, phi) << std::endl;
		}
		if(!(1 <= e && e < n)){
			std::cout << e << " " << n << std::endl;
		}
		if(!(IsPrime(p) && IsPrime(q))){
			std::cout << p << " " << q << std::endl;
		}
		*/
	}
	d = CalculateDecryptionKey(e, phi);
 
	std::vector<int> vec;
	std:: cout << p << " " << q << " " << phi << " " << d << std::endl;
	for(unsigned int i = 0; i < inputs.size(); i++)
	{
		vec.push_back(DecryptInteger(inputs[i], d, n));
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
	for(unsigned int i = 0; i < inputs.size(); i++)
	{
		std::cout << OutputFromInt(vec.at(i));
	}
 
	return 0;
}
