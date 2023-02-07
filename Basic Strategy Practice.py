from random import randint

ls = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "K", "Q", "A"]
print("No.".ljust(4, " "), "Player".ljust(9, " "), "Dealer".ljust(9, " "), "Prediction")
print(36 * "-")
n, flag = 1, True
while True:
  print(str(n).ljust(5, " "), end="")
  if flag:
    print((ls[randint(0, 11)] + " " + ls[randint(0, 11)]).ljust(10, " "), end="") # Hard
  else:
    print(("A " + ls[randint(0, 7)]).ljust(10, " "), end="") # Soft
  # randPair = randint(0, 12) # Pair
  # print((ls[randPair] + " " + ls[randPair]).ljust(10, " "), end="") # Pair
  # print((ls[randint(0, 12)] + " " + ls[randint(0, 12)]).ljust(10, " "), end="") # Both
  print(ls[randint(0, 12)].ljust(10, " "), end="")
  input()
  n += 1
  flag ^= True
