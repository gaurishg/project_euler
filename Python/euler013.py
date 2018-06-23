numbers = []
for i in range(100):
    numbers.append(int(input()[:11])) # only starting 11 digits are enough

print(str(sum(numbers))[:10])