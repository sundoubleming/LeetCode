#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isIsomorphic(char * s, char * t) {
   if (s == NULL && t == NULL) {
      return true;
   }
   if (s == NULL || t == NULL || strlen(s) != strlen(t)) {
      return false;
   }

   int idx_s[128] = { 0 };
   int idx_t[128] = { 0 };

   for (int i = 0; i < strlen(s); ++i) {
      if (idx_s[s[i]] != idx_t[t[i]]) {
         return false;
      }
      idx_s[s[i]] = i + 1;
      idx_t[t[i]] = i + 1;
   }

   return true;
}

int main(int argc, char **argv) {
   char *s = argv[1];
   char *t = argv[2];
   if (isIsomorphic(s, t)) {
      printf("TRUE\n");
   }
   else {
      printf("FALSE\n");
   }
   return 0;
}