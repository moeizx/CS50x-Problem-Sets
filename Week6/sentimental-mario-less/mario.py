while True:
    try:
        height = int(input("Height: "))
        if 0 < height < 9:
            break
        print("Invalid Input")
    except ValueError:
        print("Invalid Input")

for i in range(height):
    for space in range(height-i-1):
        print(" ", end="")

    for brick in range(i+1):
        print("#", end="")

    print()
