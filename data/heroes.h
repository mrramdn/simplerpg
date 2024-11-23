// heroes.h (header) untuk inisialisasi
#ifndef HEROES_H
#define HEROES_H

#include <stdbool.h>

// Struktur untuk data skill
typedef struct {
    char name[50];
    int damage;
    char description[100];
} Skill;

// Struktur untuk data hero
typedef struct {
    char name[50];
    char role[20];
    int hp;
    int max_hp;
    int attack;
    int defense;
    Skill ultimate;
    bool skill_used;
} Hero;

// Fungsi untuk inisialisasi hero
void init_heroes(Hero heroes[]);

// Fungsi untuk menampilkan info hero
void display_hero_info(Hero *hero);

#endif
