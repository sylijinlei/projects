#ifndef  _PLAYER_H
#define  _PLAYER_H
#include <pthread.h>

struct player{
    ListHead mp3_list;
    pthread_t player_tid;
};
void player_init();

#endif  // _PLAYER_H
