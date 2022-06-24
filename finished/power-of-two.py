def wasd(num):
    if num == 1:
        return True
    elif num == 0:
        return False
    elif num % 2 == 0:
        return wasd(num//2)
    else:
        return False
print(wasd(20))
for i in range(100):
    if wasd(i) == True:
        print(i, 'True')

