#include "history.h"

#include <stdint.h>
#include <stdlib.h>

#define INITIAL_HISTORY_CAPACITY 8U

void history_init(MoveHistory *history) {
    if (history == NULL) {
        return;
    }

    history->items = NULL;
    history->count = 0;
    history->capacity = 0;
}

int history_push(MoveHistory *history, Move move) {
    /* STUDENT TODO 4: Append one move to the resizable history array. */
    if (history == NULL) {
        return 0;
    }
    if (history->count == history->capacity) {
        size_t new_capacity;
        if (history->capacity == 0) {
            new_capacity = INITIAL_HISTORY_CAPACITY;
        } else {
            new_capacity = history->capacity * 2;
        }
        Move *new_items = realloc(history->items,new_capacity * sizeof *new_items);
        if(new_items == NULL) {
            return 0;
        }
        history->items = new_items;
        history->capacity = new_capacity;
    }
    history->items[history->count] = move;
    history->count ++;
    return 1;
}

int history_pop(MoveHistory *history, Move *result) {
    /* STUDENT TODO 4: Remove and return the most recent move. */
    if (history == NULL || result == NULL || history->count == 0) {
        return 0;
    }
    history->count --;
    *result = history->items[history->count];
    return 1;
}

void history_clear(MoveHistory *history) {
    if (history == NULL) {
        return;
    }

    history->count = 0;
}

void history_destroy(MoveHistory *history) {
    /* STUDENT TODO 4: Release all storage owned by the history. */
    if (history == NULL) {
        return;
    }
    free(history->items);
    history_init(history);
}
