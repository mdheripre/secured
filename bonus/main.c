/*
** EPITECH PROJECT, 2023
** MAIN.C
** File description:
** main function for secured program
*/

#include "../include/hashtable.h"

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 100);
    int a = 0;

    //ht_insert(&a, &a, &a);
    // ht_dump(a);
    // ht_insert(ht, "toto", "otot");
    // ht_insert(ht, "toto", "otot");
    // ht_dump(ht);
    // ht_insert(ht, "toto", "otot");
    // ht_dump(ht);
    // ht_insert(ht, "toto", "oot");
    // ht_dump(ht);
    ht_insert(ht, "toto", "otot");
    ht_dump(ht);
    ht_insert(ht, "too", "otot");
    ht_dump(ht);
    printf("search : %s\n", ht_search(ht, "otot"));
    printf("search : %s\n", ht_search(ht, "too"));
    printf("search : %s\n", ht_search(ht, NULL));
    printf("search : %s\n", ht_search(ht, "otototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototot"));
    // ht_dump(NULL);
    // ht_search(NULL, NULL);
    // ht_delete(NULL, NULL);
    // ht_insert(122222222222, NULL, NULL);
    // ht_insert(ht, "alpha", "océan");
    // ht_insert(ht, "alphb", "océan");
    // ht_insert(ht, "alpha", "océanide");
    // ht_insert(ht, "bravo", "océam");
    // ht_insert(ht, "charlie", "rivière");
    // printf("delta foret : %d\n", ht_insert(ht, "delta", "forêt"));
    // printf("looking for %s: %s\n", "delta", ht_search(ht, "delta"));
    // ht_insert(ht, "echo", "desert");
    // ht_insert(ht, "foxtrot", "glacier");
    // ht_insert(ht, "golf", "volcan");
    // ht_insert(ht, "hotel", "vallée");
    // ht_insert(ht, "india", "canyon");
    // ht_insert(ht, "juliet", "prairie");
    // ht_insert(ht, "kilo", "jungle");
    // ht_insert(ht, "lima", "falaise");
    // ht_insert(ht, "mike", "plateau");
    // ht_insert(ht, "november", "lagune");
    // ht_insert(ht, "oscar", "marécage");
    // ht_insert(ht, "papa", "toundra");
    // ht_insert(ht, "quebec", "île");
    // ht_insert(ht, "romeo", "steppe");
    // ht_insert(ht, "sierra", "oasis");
    // my_printf("hash tango fjdord : %d\n", hash("tango", 100));
    // ht_insert(ht, "tango", "fjord");
    // printf("tango fjord : %s\n", ht_search(ht, "tango"));
    // ht_insert(ht, "uniform", "archipel");
    // ht_dump(ht);
    // ht_insert(ht, "uniform", "toto");
    // ht_dump(ht);
    // ht_insert(ht, "victor", "atoll");
    // ht_insert(ht, "whiskey", "iceberg");
    // ht_insert(ht, "xray", "dune");
    // ht_insert(ht, "yankee", "delta");
    // ht_insert(ht, "zulu", "grotte");
    // ht_insert(ht, "apple", "savane");
    // ht_insert(ht, "banana", "colline");
    // ht_insert(ht, "cherry", "récif");
    // ht_insert(ht, "0", "sommet");
    // ht_insert(ht, "elderberry", "abysse");
    // ht_insert(ht, "fig", "brousse");
    // ht_insert(ht, "grape", "taïga");
    // ht_insert(ht, "honeydew", "estuaire");
    // ht_insert(ht, "kiwi", "crête");
    // ht_insert(ht, "lemon", "havre");
    // ht_insert(ht, "mango", "péninsule");
    // ht_insert(ht, "nectarine", "falaise");
    // ht_insert(ht, "orange", "détroit");
    // ht_insert(ht, "pear", "désert");
    // printf("pear : %s\n", ht_search(ht, "pear"));
    // printf("looking for %s: %s\n", "alpha", ht_search(ht, "alpha"));
    // printf("looking for %s: %s\n", "bravo", ht_search(ht, "bravo"));
    // printf("looking for %s: %s\n", "apple", ht_search(ht, "apple"));
    // printf("looking for %s: %s\n", "quebec", ht_search(ht, "quebec"));
    // printf("looking for %s: %s\n", "zulu", ht_search(ht, "zulu"));
    // printf("looking for %s: %s\n", "juliet", ht_search(ht, "juliet"));
    // printf("looking for %s: %s\n", "zulu", ht_search(ht, "zulu"));
    // ht_delete(ht, "delta");
    // ht_delete(ht, "lemon");
    // ht_delete(ht, "xray");
    // ht_delete(ht, "zulu");
    // ht_delete(ht, "zulu");
    // ht_delete(ht, "cheese");
    // ht_delete(ht, "sdfghjjcgfghj");
    // ht_dump(ht);
    delete_hashtable(ht);
}
