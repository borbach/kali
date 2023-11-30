# Initialize sum variable
sum = 0

while True:
    try:
        # Get input from the user
        number = int(input("Enter a number: "))

        # Check if the number is odd
        if number % 2 != 0:
            print(number, "is odd")
        else:
            print(number, "is even")

        # Add the number to the sum
        sum += number
    except ValueError:
        print("Please enter a valid number.")
        continue

    # Ask the user if they want to continue
    choice = input("Do you want to enter another number? (y/n) ")
    if choice.lower() != "y":
        break

# Print the sum of all numbers
print("The sum of all numbers is:", sum)

