#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heroes.h"

// Membersihkan layar untuk ui
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Calculate damage
int calculaute_damage(int attack, int defense) {
    int damage = attack - (defense * 2);
    return damage > 0 ? damage : 1;
}

// Menggunakan ultimate skill
void use_ultimate(Hero *attacker, Hero *defender) {
    if (attacker->skill_used) {
        printf("\n❌ Ultimate already used!\n");
        return;
    }
    
    printf("\n⚡ %s uses %s!\n", attacker->name, attacker->ultimate.name);
    defender->hp -= attacker->ultimate.damage;
    printf("💥 Deals %d damage!\n", attacker->ultimate.damage);
    attacker->skill_used = true;
}

// Menampilkan battle status
void show_battle_status(Hero *player, Hero *enemy) {
    clear_screen();
    printf("\n=== BATTLE STATUS ===\n");
    printf("\n🦸 %s\n", player->name);
    display_health_bar(player);
    printf("\n\n👿 %s\n", enemy->name);
    display_health_bar(enemy);
    printf("\n\n");
}
