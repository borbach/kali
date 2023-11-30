number = 0
my_list=[]
total=0
while(number!="99"):
    number=input("Please enter a number( 99 to quit): ")
    if(int(number) % 2):
        print("odd number")
    else:
        print("even number")
    my_list.append(number)
    print(my_list)
    for item in my_list:
        total += int(item)
    print(total)
    total=0


for i in range(10):
    print(i)
    if(i % 2):
        print("odd")
    else:
        print("even")


if(1==2):
    print("true")
else:
    print("false")

