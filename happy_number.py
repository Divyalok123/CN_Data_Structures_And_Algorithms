
def sumofsquares(num):
    add = 0
    while num:
        add += (num % 10)**2
        num //= 10
    return add


def happynumber(num):
    fast = num
    slow = num
    while True:
        slow = sumofsquares(slow)
        fast = sumofsquares(sumofsquares(fast))
        if(slow != fast):
            continue
        else:
            break


num = int(input())
if(happynumber(num)):
    print('true')
else:
    print('false')
