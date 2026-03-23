from cs50 import get_float

def print_coins(change):
    coins = 0
    if change == 0:
        return coins

    coins += change//25
    change %= 25

    coins += change//10
    change %= 10

    coins += change//5
    change %= 5

    coins += change//1
    change %= 1

    return coins

while True:
    try:
        change = get_float("Change: ")
        if change >= 0:
            break
        print("Invalid value\nEnter a non-negative value")
    except ValueError:
        print("Invalid value\nEnter a non-negative value")

change = round(change*100)
print(print_coins(change))
