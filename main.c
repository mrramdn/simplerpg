#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Simple character structure
typedef struct {
    char name[50];
    int hp;
    int attack;
    int defense;
    char skill_name[50];
    bool skill_used;
} Character;

// Battle actions
typedef enum {
    ATTACK = 1,
    DEFEND,
    USE_SKILL
} Action;

// Initialize characters
void init_characters(Character *player, Character *enemy) {
    // Initialize player (Warrior)
    strcpy(player->name, "Warrior");
    player->hp = 100;
    player->attack = 15;
    player->defense = 10;
    strcpy(player->skill_name, "Power Strike");
    player->skill_used = false;
    
    // Initialize enemy (Dragon)
    strcpy(enemy->name, "Dragon");
    enemy->hp = 120;
    enemy->attack = 20;
    enemy->defense = 8;
    strcpy(enemy->skill_name, "Fire Breath");
    enemy->skill_used = false;
}

// Calculate damage
int calculate_damage(int attack, int defense) {
    int damage = attack - defense;
    return damage > 0 ? damage : 1;
}

// Execute skill
void use_skill(Character *attacker, Character *defender) {
    if (attacker->skill_used) {
        printf("Skill already used!\n");
        return;
    }
    
    printf("%s uses %s!\n", attacker->name, attacker->skill_name);
    int skill_damage = attacker->attack * 2;
    defender->hp -= skill_damage;
    printf("Deals %d damage!\n", skill_damage);
    attacker->skill_used = true;
}

// Display battle status
void show_status(Character *player, Character *enemy) {
    printf("\n%s HP: %d | %s HP: %d\n", 
           player->name, player->hp,
           enemy->name, enemy->hp);
}

// Main battle system
void battle(Character *player, Character *enemy) {
    printf("\nBattle Start: %s vs %s!\n", player->name, enemy->name);
    
    while (player->hp > 0 && enemy->hp > 0) {
        show_status(player, enemy);
        
        // Player turn
        printf("\nYour turn!\n");
        printf("1. Attack\n2. Defend\n3. Use Skill\n");
        printf("Choose action (1-3): ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case ATTACK: {
                int damage = calculate_damage(player->attack, enemy->defense);
                enemy->hp -= damage;
                printf("You deal %d damage!\n", damage);
                break;
            }
            case DEFEND:
                player->defense += 5;
                printf("Defense increased!\n");
                break;
            case USE_SKILL:
                use_skill(player, enemy);
                break;
            default:
                printf("Invalid choice! Turn skipped.\n");
                break;
        }
        
        if (enemy->hp <= 0) {
            printf("\n%s wins!\n", player->name);
            break;
        }
        
        // Enemy turn
        printf("\nEnemy turn!\n");
        if (!enemy->skill_used && enemy->hp < 50) {
            use_skill(enemy, player);
        } else {
            int damage = calculate_damage(enemy->attack, player->defense);
            player->hp -= damage;
            printf("%s attacks for %d damage!\n", enemy->name, damage);
        }
        
        if (player->hp <= 0) {
            printf("\n%s wins!\n", enemy->name);
            break;
        }
    }
}

int main() {
    Character player, enemy;
    init_characters(&player, &enemy);
    battle(&player, &enemy);
    return 0;
}