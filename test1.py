sum = 0
while True:
  try:
    # Get the user's input
    number = int(input("Enter a number: "))

    # Check if the number is odd or even
    if number % 2 == 0:
      print(number, "is even")
    else:
      print(number, "is odd")

    # Add the number to the sum
    sum += number

  except ValueError:
    print("Please enter a valid number.")
    continue

  # Check if the user wants to exit
  choice = input("Do you want to enter another number? (yes/no) ")
  if choice.lower() != "yes":
    break

# Print the sum of all the numbers
print("The sum of all the numbers is:", sum)

