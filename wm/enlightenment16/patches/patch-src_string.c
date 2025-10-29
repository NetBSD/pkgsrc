$NetBSD: patch-src_string.c,v 1.1 2025/10/29 23:50:00 gutteridge Exp $

Use ctype.h correctly.

--- src/string.c.orig	2025-06-23 13:11:03.000000000 +0000
+++ src/string.c
@@ -34,8 +34,8 @@ Estrcasecmp(const char *s1, const char *
 
     for (;;)
     {
-        ch1 = toupper(*s1++);
-        ch2 = toupper(*s2++);
+        ch1 = toupper((unsigned char)*s1++);
+        ch2 = toupper((unsigned char)*s2++);
         if (ch1 == '\0' || ch1 != ch2)
             break;
     }
@@ -59,8 +59,8 @@ Estrcasestr(const char *haystack, const 
             break;
         for (;;)
         {
-            ch1 = toupper(*s1++);
-            ch2 = toupper(*s2++);
+            ch1 = toupper((unsigned char)*s1++);
+            ch2 = toupper((unsigned char)*s2++);
             if (ch2 == '\0')
                 return haystack;
             if (ch1 == '\0' || ch1 != ch2)
@@ -97,7 +97,7 @@ EnvSubst(const char *str, char *bptr, un
         /* $ENV_VAR - Name is validted */
         for (; *p2 != '\0'; p2++)
         {
-            if (!(isalnum(*p2) || *p2 == '_'))
+            if (!(isalnum((unsigned char)*p2) || *p2 == '_'))
                 break;
         }
         len = p2 - p1;
@@ -129,13 +129,13 @@ Estrtrim(char *s)
 {
     int             l;
 
-    while (isspace(*s))
+    while (isspace((unsigned char)*s))
         s++;
     if (!*s)
         return s;
 
     l = strlen(s);
-    while (isspace(s[l - 1]))
+    while (isspace((unsigned char)s[l - 1]))
         l--;
     s[l] = '\0';
 
@@ -150,7 +150,7 @@ Estrtrim2(char *s)
 {
     int             len, len2, ch, quote;
 
-    while (isspace(*s))
+    while (isspace((unsigned char)*s))
         s++;
 
     quote = '\0';
