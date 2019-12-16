

list = [[0]*4 for i in range(3)]

print(list)


for j in range(len(list)):
    for k in range(len(list[j])):
        ans = int(input("숫자를 입력해 주세요"))
        list[j][k] = ans 

for a in range(len(list)):
    for b in range(len(list[a])):
        print(f"[{a}][{b}]: ?", end=" ")
        if b == 3 or b == 6 or b == 9:
            print("\n")

