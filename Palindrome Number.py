def palindrome():
    num_input = int(input())
    if num_input < 0:
        return "false"
    mid = len(str(num_input)) // 2
    lastnum = num_input
    temp = 0
    for i in range(mid+1):
        temp += (lastnum % 10)*(10**(mid-i))
        lastnum //= 10
    firstnum = num_input
    firstnum //= 10**mid
    print(firstnum,temp)
    if firstnum == temp:
        return "true"
    else:
        return "false"

print(palindrome())