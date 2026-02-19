$NetBSD: patch-uni2ascii.c,v 1.1 2026/02/19 15:19:19 wiz Exp $

--- uni2ascii.c.orig	2026-02-19 15:03:42.107970203 +0000
+++ uni2ascii.c
@@ -2689,7 +2689,7 @@ int SubsAvailable = 0;
  * search may be advisable. For the time being we just do a linear search.
  */
 
-SubstituteChar(UTF32 c) {
+int SubstituteChar(UTF32 c) {
   int i;
   for(i = 0; i < SubCnt; i++) {
     if(c == SubList[i].u) {
@@ -2703,7 +2703,7 @@ SubstituteChar(UTF32 c) {
   return 0;
 }
 
-AddCustomSubstitution(char *str){
+void AddCustomSubstitution(char *str){
   char *Left;
   char *Right;
   char *Delim;
@@ -2798,6 +2798,7 @@ int main (int ac, char *av[])
   extern int optopt;
   extern UTF32 UTF8in(int,int *,unsigned char **);
 
+  extern void putu8 (unsigned long);
   extern int CountSlots(char *);
   extern void ListFormatArguments(short);
   extern void SetFormat(char *, int *, short *,int *, short *, short *);
