from os import system
from msvcrt import kbhit, getch
from math import ceil
from termcolor import colored

# Insurance (% Player Advantage):
# +0.12 -> For Single Deck Game
# +0.035 -> For 4 Deck Game

# Index 0 -> 10s, 1 -> A, 2 to 9 -> 2 to 9
HiOpt1 = [-1, 0, 0, 1, 1, 1, 1, 0, 0, 0]
HiOpt2 = [-2, 0, 1, 1, 2, 2, 1, 1, 0, 0]

def getInput(inputStr):
  temp = ''
  while temp == '':
    temp = input(inputStr)
  return temp

def show():
  global bankroll, combRunningCount, trueCount, playerAdvantage, tableMin, flag
  curWin = float(getInput('\n\nHow much do you win? '))
  bankroll += curWin
  system('clear')
  print('{:15}{:15}{}'.format('Running_Count', 'True_Count', 'Player_Advantage'))
  print('-' * 46)
  print('{:<15}{:<15}{}\n'.format(round(combRunningCount, 2), round(trueCount, 2), round(playerAdvantage, 2)))

  print(colored('BET: ' + str(tableMin + (round(playerAdvantage * ((bankroll - tableMin) / 100)) if playerAdvantage > 0 else 0)), 'green'))
  if (noOfDeck == 1 and trueCount >= 2) or (noOfDeck > 1 and trueCount >= 3):
    print(colored('Take Insurance', 'green'))
  flag = True

noOfDeck = float(getInput('Enter the no. of Decks: '))
BSE = float(getInput('Enter the Basic Strategy Expectation (BSE): '))
tableMin = float(getInput('Enter the Table Minimum (Bet): '))
bankroll = float(getInput('Enter Your Bankroll: '))
runningCount, remCardInShoe, aceCount = 0, 52 * noOfDeck, 4 * noOfDeck
flag = True

while True:
  if kbhit():
    c = getch()

    # To do the calculations and tells the final results
    if ord(c) == 13:  # ASCII: Enter -> 13
      combRunningCount = runningCount + (aceCount - ceil(remCardInShoe / 13))
      trueCount = combRunningCount / (remCardInShoe / 52)
      playerAdvantage = BSE + 0.515 * trueCount
      show()
      continue

    # To reset the values
    if ord(c) == ord('r'):
      if input('\nDo you want to reset (y/n): ') == 'y':
        runningCount, remCardInShoe, aceCount = 0, 52 * noOfDeck, 4 * noOfDeck
        system('clear')
        print('Reset Successful\n')
      else:
        print("Continue the Current Hand's Cards: ", end='', flush=True)
      continue

    # For HiOpt1 and HiOpt2 (use numpad)
    if ord(c) >= ord('0') and ord(c) <= ord('9'):
      if c == '1':
        aceCount -= 1
      else:
        runningCount += HiOpt2[ord(c) - ord('0')]
      remCardInShoe -= 1
      if ord(c) == ord('1'):
        print('A ', end='', flush=True)
      elif ord(c) == ord('0'):
        print('10 ', end='', flush=True)
      else:
        print(chr(ord(c)), end=' ', flush=True)
  if flag:
    print("\nEnter the Current Hand's Cards: ", end='', flush=True)
    flag = False
