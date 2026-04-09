#ifndef STRUCTS_H
#define STRUCTS_H

// Define your structs here
struct u_state {
    int health_points;
    int mana_points;
    int stamina;
};

struct user {
    char *name;
    struct u_state *state;
};

#endif // STRUCTS_H
