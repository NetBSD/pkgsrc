$NetBSD: patch-ndbm_xdndbm.c,v 1.2 2023/07/07 12:45:25 nia Exp $

Make `int` types explicit, don't own-declare lseek()
(gives type mismatch).

--- ndbm/xdndbm.c.orig	1997-05-04 22:05:18.000000000 +0000
+++ ndbm/xdndbm.c
@@ -12,6 +12,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
@@ -28,8 +29,8 @@
 #ifdef NET_BYTE_ORDER
 #include <netinet/in.h>
 
-static convert_after_read(char buf[PBLKSIZ]);
-static convert_before_write(char buf[PBLKSIZ]);
+static int convert_after_read(char buf[PBLKSIZ]);
+static int convert_before_write(char buf[PBLKSIZ]);
 
 #undef DEBUG
 #endif
@@ -52,9 +53,6 @@ static  int finddatum();
 static  int delitem();
 static  int additem();
 
-extern  int errno;
-extern  long lseek();
-
 #ifdef DEBUG
 static chkblk(char buf[PBLKSIZ]);
 #endif
@@ -142,7 +140,7 @@ dbm_fetch(db, key)
 register DBM *db;
 datum key;
 {
-  register i;
+  register int i;
   datum item;
 
   if (dbm_error(db))
@@ -168,7 +166,7 @@ dbm_delete(db, key)
 register DBM *db;
 datum key;
 {
-  register i;
+  register int i;
 
   if (dbm_error(db))
     return (-1);
@@ -216,7 +214,7 @@ register DBM *db;
 datum key, dat;
 int replace;
 {
-  register i;
+  register int i;
   datum item, item1;
   char ovfbuf[PBLKSIZ];
 
@@ -438,7 +436,7 @@ getbit(db)
 register DBM *db;
 {
   long bn;
-  register b, i, n;
+  register int b, i, n;
 
   if (db->dbm_bitno > db->dbm_maxbno)
     return (0);
@@ -496,7 +494,7 @@ makdatum(buf, n)
 char buf[PBLKSIZ];
 {
   register short *sp;
-  register t;
+  register int t;
   datum item;
 
   sp = (short *)buf;
@@ -624,7 +622,7 @@ delitem(buf, n)
 char buf[PBLKSIZ];
 {
   register short *sp, *sp1;
-  register i1, i2;
+  register int i1, i2;
 
   sp = (short *)buf;
   i2 = sp[0];
@@ -667,7 +665,7 @@ char buf[PBLKSIZ];
 datum item, item1;
 {
   register short *sp;
-  register i1, i2;
+  register int i1, i2;
 
   sp = (short *)buf;
   i1 = PBLKSIZ;
@@ -695,7 +693,7 @@ static
 chkblk(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   t = PBLKSIZ;
@@ -719,7 +717,7 @@ int
 convert_after_read(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   sp[0] = ntohs(sp[0]);
@@ -745,7 +743,7 @@ int
 convert_before_write(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   t = PBLKSIZ;
