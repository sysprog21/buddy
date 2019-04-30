#ifndef INTERNAL_LIST_H
#define INTERNAL_LIST_H

/* circular doubly-linked list */
typedef struct list_t {
    struct list_t *prev, *next;
} list_t;

/*
 * Initialize a list to empty. Because these are circular lists, an "empty"
 * list is an entry where both links point to itself. This makes insertion
 * and removal simpler because they do not need any branches.
 */
static void list_init(list_t *list)
{
    list->prev = list;
    list->next = list;
}

/*
 * Append the provided entry to the end of the list. This assumes the entry
 * is not in a list already because it overwrites the linked list pointers.
 */
static void list_push(list_t *list, list_t *entry)
{
    list_t *prev = list->prev;
    entry->prev = prev;
    entry->next = list;
    prev->next = entry;
    list->prev = entry;
}

/*
 * Remove the provided entry from whichever list it is currently in. This
 * assumes that the entry is in a list. You do not need to provide the list
 * because the lists are circular, so the list's pointers will automatically
 * be updated if the first or last entries are removed.
 */
static void list_remove(list_t *entry)
{
    list_t *prev = entry->prev;
    list_t *next = entry->next;
    prev->next = next;
    next->prev = prev;
}

/*
 * Remove and return the first entry in the list or NULL if the list is empty.
 */
static list_t *list_pop(list_t *list)
{
    list_t *back = list->prev;
    if (back == list)
        return NULL;
    list_remove(back);
    return back;
}

#endif
