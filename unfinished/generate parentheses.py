a = []
def wasd(n):
    output = '('
    if n == 1:
        output += ')'
        a.append(output)
        return output
    n -= 1
    for i in range(n):
        output += wasd(i) + ')'
        a.append(output)
    return output 

if __name__ == '__main__':
    num = int(input())
    wasd(num)
    print(a)


