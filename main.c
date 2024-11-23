#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heroes.h"
#include "mechanics.c"


// Fungsi untuk menjalankan pemilihan hero
int choose_hero(Hero heroes[]) {
    int choice;
    while (1) {
        clear_screen();
        printf("\n===== CHOOSE YOUR HERO =====\n\n");
        
        for (int i = 0; i < 4; i++) {
            printf("%d. %s (%s)\n", i + 1, heroes[i].name, heroes[i].role);
            display_hero_info(&heroes[i]);
            printf("\n");
        }
        
        printf("\nSelect your hero (1-4): ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 4) {
            return choice - 1;
        }
        printf("\nInvalid choice! Please try again.\n");
    }
}

// Fungsi utama
int main() {
    srand(time(NULL));
    Hero heroes[4];
    init_heroes(heroes);
    
    // Pilih hero
    int player_choice = choose_hero(heroes);
    
    // Pilih enemy random selain hero player
    int enemy_choice;
    do {
        enemy_choice = rand() % 4;
    } while (enemy_choice == player_choice);
    
    clear_screen();
    printf("\nYour Hero:\n");
    display_hero_info(&heroes[player_choice]);
    printf("\nEnemy Hero:\n");
    display_hero_info(&heroes[enemy_choice]);
    
    printf("\nPress Enter to start battle...");
    getchar();
    getchar();
    
    battle(&heroes[player_choice], &heroes[enemy_choice]);
    
    return 0;
}
