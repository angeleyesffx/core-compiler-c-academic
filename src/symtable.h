#ifndef SYMTABLE_H
#define SYMTABLE_H

/*
 * Symbol table — hash table with chaining.
 *
 * Based on: Cormen, Leiserson, Rivest, Stein — "Introduction to Algorithms"
 * (CLRS), 4th ed., Chapter 11 — Hash Tables.
 *
 * Each identifier is stored in a bucket determined by a hash of its name.
 * Collisions are resolved by chaining (linked list per bucket).
 *
 * Complexity (n = total entries, alpha = load factor n/m):
 *   Insert  : O(1)
 *   Lookup  : O(1) expected  (O(n) worst case — all in same bucket)
 *   Remove  : O(n/m) expected per removed entry
 *
 * SYMTABLE_BUCKETS is chosen as a prime to improve hash distribution
 * (CLRS §11.3.1 — Division method).
 */

#define SYMTABLE_BUCKETS 101
#define MAX_NAME         100

typedef struct SymEntry {
    char  name[MAX_NAME];
    int   scope;
    struct SymEntry *next;  /* collision chain */
} SymEntry;

typedef struct {
    SymEntry *buckets[SYMTABLE_BUCKETS];
} SymTable;

void      symtable_init(SymTable *t);
void      symtable_insert(SymTable *t, const char *name, int scope);
SymEntry *symtable_lookup(SymTable *t, const char *name);
void      symtable_remove_scope(SymTable *t, int scope);
void      symtable_print(const SymTable *t);
void      symtable_free(SymTable *t);

#endif /* SYMTABLE_H */
