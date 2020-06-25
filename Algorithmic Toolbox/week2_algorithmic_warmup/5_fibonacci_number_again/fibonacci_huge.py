# Uses python3
import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m

def get_fibonacci_huge_fast(n, m):
	n = n % pisano_period(m)
	if n==0 or n==1 :
		return n
	prev = 0
	curr = 1
	while n>1 :
		tmp = curr;
		curr = prev+curr
		prev = tmp
		n -= 1
	return curr%m

def pisano_period(m) :
	prev = 0
	curr = 1
	count = 0
	while True :
		tmp = curr
		curr = prev + curr
		prev = tmp
		curr = curr%m
		prev = prev%m
		count += 1
		if prev==0 and curr==1 :
			break
	return count


if __name__ == '__main__':
    input = sys.stdin.read()
    n, m = map(int, input.split())
    #n,m = map(int,input().split())
    print(get_fibonacci_huge_fast(n, m))
    #print(pisano_period(m))
