$NetBSD: patch-xb__check.c,v 1.1 2026/03/23 10:50:44 nia Exp $

Fix build on FreeBSD, which has isnumber(3).

gets(3) considered harmful.

--- xb_check.c.orig	1997-05-15 20:38:25.000000000 +0000
+++ xb_check.c
@@ -145,7 +145,7 @@ char *elem(char *s, int elnum)
 }
 
 /* boolean that checks if a string is numeric */
-int isnumber(char *s)
+int my_isnumber(char *s)
 {
   if(atoi(s)==0 && *s!='0')
     return 0;
@@ -160,6 +160,8 @@ int isnumber(char *s)
   return 1;
 }
 
+#define isnumber my_isnumber
+
 /* return true if the resource is a color resource */
 int iscolorres(int i)
 {
@@ -303,7 +305,7 @@ even 'appres <progname/classname> | xb_c
     }
   }
 
-  while(gets(line)!=NULL)
+  while(fgets(line, sizeof(line), stdin)!=NULL)
   {
     if(line[0]=='!')
       continue;
