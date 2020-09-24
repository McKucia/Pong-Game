#include "GameManager.hpp"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL,"");

    GameManager game("Player 1", "Player 2");
    game.newGame();

    return 0;
}
