#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"

/*
 * djb2 hash function — O(|key|), effectively O(1) for bounded identifiers.
 *
 * h(i) = h(i-1) * 33 + c
 *
 * Maps the string key to a bucket index in [0, SYMTABLE_BUCKETS).
 * The prime bucket count (101) reduces clustering (CLRS §11.3.1).
 */
static unsigned int hash_symbol(const char *key) {
    unsigned int h = 5381;
    while (*key)
        h = (h << 5) + h + (unsigned char)*key++;   /* h * 33 + c */
    return h % SYMTABLE_BUCKETS;
}

void symtable_init(SymTable *t) {
    for (int i = 0; i < SYMTABLE_BUCKETS; i++)
        t->buckets[i] = NULL;
}

/*
 * CHAINED-HASH-INSERT (CLRS §11.2)
 * Insert at the head of the chain — O(1).
 */
void symtable_insert(SymTable *t, const char *name, int scope) {
    unsigned int idx = hash_symbol(name);

    SymEntry *entry = malloc(sizeof(SymEntry));
    if (!entry) { fprintf(stderr, "Out of memory\n"); exit(1); }

    strncpy(entry->name, name, MAX_NAME - 1);
    entry->name[MAX_NAME - 1] = '\0';
    entry->scope = scope;
    entry->next  = t->buckets[idx];   /* head insertion */
    t->buckets[idx] = entry;
}

/*
 * CHAINED-HASH-SEARCH (CLRS §11.2)
 * Returns the first entry whose name matches, or NULL — O(1) expected.
 */
SymEntry *symtable_lookup(SymTable *t, const char *name) {
    unsigned int idx = hash_symbol(name);
    SymEntry *e = t->buckets[idx];
    while (e) {
        if (strcmp(e->name, name) == 0) return e;
        e = e->next;
    }
    return NULL;
}

/*
 * Remove all entries belonging to a given scope.
 * Called when a block ends (scope closes).
 * Traverses every bucket — O(n + m) where m = SYMTABLE_BUCKETS.
 */
void symtable_remove_scope(SymTable *t, int scope) {
    for (int i = 0; i < SYMTABLE_BUCKETS; i++) {
        SymEntry **p = &t->buckets[i];
        while (*p) {
            if ((*p)->scope == scope) {
                SymEntry *del = *p;
                *p = del->next;
                free(del);
            } else {
                p = &(*p)->next;
            }
        }
    }
}

void symtable_print(const SymTable *t) {
    printf("SYMBOL TABLE:\n");
    for (int i = 0; i < SYMTABLE_BUCKETS; i++) {
        const SymEntry *e = t->buckets[i];
        while (e) {
            printf("  ['%s', scope=%d]\n", e->name, e->scope);
            e = e->next;
        }
    }
}

void symtable_free(SymTable *t) {
    for (int i = 0; i < SYMTABLE_BUCKETS; i++) {
        SymEntry *e = t->buckets[i];
        while (e) {
            SymEntry *next = e->next;
            free(e);
            e = next;
        }
        t->buckets[i] = NULL;
    }
}
