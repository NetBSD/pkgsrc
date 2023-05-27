$NetBSD: patch-ndbm_xdndbm.c,v 1.1 2023/05/27 15:22:36 he Exp $

Make `int` types explicit, don't own-declare lseek() on NetBSD
(gives type mismatch).

--- ndbm/xdndbm.c.orig	1997-05-04 22:05:18.000000000 +0000
+++ ndbm/xdndbm.c
@@ -28,8 +28,8 @@
 #ifdef NET_BYTE_ORDER
 #include <netinet/in.h>
 
-static convert_after_read(char buf[PBLKSIZ]);
-static convert_before_write(char buf[PBLKSIZ]);
+static int convert_after_read(char buf[PBLKSIZ]);
+static int convert_before_write(char buf[PBLKSIZ]);
 
 #undef DEBUG
 #endif
@@ -53,7 +53,9 @@ static  int delitem();
 static  int additem();
 
 extern  int errno;
+#ifndef __NetBSD__
 extern  long lseek();
+#endif
 
 #ifdef DEBUG
 static chkblk(char buf[PBLKSIZ]);
@@ -142,7 +144,7 @@ dbm_fetch(db, key)
 register DBM *db;
 datum key;
 {
-  register i;
+  register int i;
   datum item;
 
   if (dbm_error(db))
@@ -168,7 +170,7 @@ dbm_delete(db, key)
 register DBM *db;
 datum key;
 {
-  register i;
+  register int i;
 
   if (dbm_error(db))
     return (-1);
@@ -216,7 +218,7 @@ register DBM *db;
 datum key, dat;
 int replace;
 {
-  register i;
+  register int i;
   datum item, item1;
   char ovfbuf[PBLKSIZ];
 
@@ -438,7 +440,7 @@ getbit(db)
 register DBM *db;
 {
   long bn;
-  register b, i, n;
+  register int b, i, n;
 
   if (db->dbm_bitno > db->dbm_maxbno)
     return (0);
@@ -496,7 +498,7 @@ makdatum(buf, n)
 char buf[PBLKSIZ];
 {
   register short *sp;
-  register t;
+  register int t;
   datum item;
 
   sp = (short *)buf;
@@ -624,7 +626,7 @@ delitem(buf, n)
 char buf[PBLKSIZ];
 {
   register short *sp, *sp1;
-  register i1, i2;
+  register int i1, i2;
 
   sp = (short *)buf;
   i2 = sp[0];
@@ -667,7 +669,7 @@ char buf[PBLKSIZ];
 datum item, item1;
 {
   register short *sp;
-  register i1, i2;
+  register int i1, i2;
 
   sp = (short *)buf;
   i1 = PBLKSIZ;
@@ -695,7 +697,7 @@ static
 chkblk(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   t = PBLKSIZ;
@@ -719,7 +721,7 @@ int
 convert_after_read(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   sp[0] = ntohs(sp[0]);
@@ -745,7 +747,7 @@ int
 convert_before_write(char buf[PBLKSIZ])
 {
   register short *sp;
-  register t, i;
+  register int t, i;
 
   sp = (short *)buf;
   t = PBLKSIZ;
