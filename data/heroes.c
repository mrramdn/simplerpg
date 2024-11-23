// data/heroes.c
#include <stdio.h>
#include <string.h>
#include "heroes.h"

// Inisialisasi hero
void init_heroes(Hero heroes[]) {
    // Lina
    strcpy(heroes[0].name, "Lina");
    strcpy(heroes[0].role, "Intelligence");
    heroes[0].hp = heroes[0].max_hp = 800;
    heroes[0].attack = 65;
    heroes[0].defense = 3;
    strcpy(heroes[0].ultimate.name, "Laguna Blade");
    heroes[0].ultimate.damage = 850;
    strcpy(heroes[0].ultimate.description, "Sends a bolt of lightning to instantly strike an enemy");
    heroes[0].skill_used = false;

    // Axe
    strcpy(heroes[1].name, "Axe");
    strcpy(heroes[1].role, "Strength");
    heroes[1].hp = heroes[1].max_hp = 1200;
    heroes[1].attack = 55;
    heroes[1].defense = 5;
    strcpy(heroes[1].ultimate.name, "Culling Blade");
    heroes[1].ultimate.damage = 650;
    strcpy(heroes[1].ultimate.description, "Executes enemies who are low on health");
    heroes[1].skill_used = false;

    // Phantom Assassin
    strcpy(heroes[2].name, "Phantom Assassin");
    strcpy(heroes[2].role, "Agility");
    heroes[2].hp = heroes[2].max_hp = 900;
    heroes[2].attack = 75;
    heroes[2].defense = 4;
    strcpy(heroes[2].ultimate.name, "Coup de Grace");
    heroes[2].ultimate.damage = 750;
    strcpy(heroes[2].ultimate.description, "Massive critical strike on enemy");
    heroes[2].skill_used = false;

    // Zeus
    strcpy(heroes[3].name, "Zeus");
    strcpy(heroes[3].role, "Intelligence");
    heroes[3].hp = heroes[3].max_hp = 700;
    heroes[3].attack = 60;
    heroes[3].defense = 2;
    strcpy(heroes[3].ultimate.name, "Thundergod's Wrath");
    heroes[3].ultimate.damage = 900;
    strcpy(heroes[3].ultimate.description, "Strikes all enemies with lightning");
    heroes[3].skill_used = false;
}
