def first_n_primes(n):
  #since 0 and 1 is not prime return false.
  if(n==1 or n==0):
    return False
   
  #Run a loop from 2 to n-1
  for i in range(2,n):
    #if the number is divisible by i, then n is not a prime number.
    if(n%i==0):
      return False
   
  #otherwise, n is prime number.
  return True
 

def first_n_primes(n):
    primes = []
    num = 2
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    return primes

def main():
    n = int(input("Enter the value of n: "))

    prime_numbers = first_n_primes(n)

    print(f"The first {n} prime numbers are:", prime_numbers)

if __name__ == "__main__":
    main()
