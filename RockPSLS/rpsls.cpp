/* This is the infamous game of Rock, Paper, Scissors, Lizard, Spock.
User chooses an option and so the computer and then the winner is decided. */

#include <iostream>
#include <stdlib.h>

int main() {

  srand(time(NULL));
  int computer = rand() % 5 + 1;

  int user = 0;

  std::cout << "====================\n";
  std::cout << "rock paper scissors lizard spock!\n";
  std::cout << "====================\n";

  std::cout << "1) ?\n";
  std::cout << "2) ?\n";
  std::cout << "3) ??\n";
  std::cout << "4) Lizard\n";
  std::cout << "5) Spock\n";

  std::cout << "shoot! ";
  std::cin >> user;
  
  // Toc heck input.
  if (user > 5 || user < 1) {
    std::cout << "Invalild Entry.\n";
  }

  std::cout << "Computer chooses: " << computer << "\n";

  // Conditions
  if (computer == user) {
    std::cout << "It's a tie!\n";
  } else if ((computer == 1 && user == 2) || (computer == 2 && user == 3) || (computer == 3 && user == 1) ||    (computer == 1 && user == 5) || (computer == 2 && user == 4) || (computer == 3 && user == 5) || (computer == 4 && user == 1) || (computer == 4 && user == 3) || (computer == 5 && user == 2) || (computer == 5 && user == 4)) {
    std::cout << "User won!\n";
    // ----------------------------------------------
  } else if ((computer == 1 && user == 3) || (computer == 2 && user == 1) || (computer == 3 && user == 2) || (computer == 1 && user == 4) || (computer == 2 && user == 5) || (computer == 3 && user == 4) || (computer == 4 && user == 2) || (computer == 4 && user == 5) || (computer == 5 && user == 1) || (computer == 5 && user == 3)) {
    std::cout << "Computer won!\n";
  } else {
    std::cout << "No one wins!!.\n";
  }
}