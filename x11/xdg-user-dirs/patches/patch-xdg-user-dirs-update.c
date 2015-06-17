$NetBSD: patch-xdg-user-dirs-update.c,v 1.1 2015/06/17 17:31:38 tron Exp $

Fix build under Solaris 10.

--- xdg-user-dirs-update.c.orig	2007-08-20 09:12:20.000000000 +0100
+++ xdg-user-dirs-update.c	2015-06-17 13:18:17.000000000 +0100
@@ -328,6 +328,24 @@
     }
 }
 
+#ifdef __sun__
+static char *
+my_strndup(const char *s, size_t n)
+{
+  char *p;
+
+  p = malloc(n + 1);
+  if (p)
+    {
+      strncpy(p, s, n);
+      p[n] = '\0';
+    }
+  return p; 
+}
+
+#define strndup my_strndup
+#endif
+
 static char **
 parse_colon_separated_dirs (const char *dirs)
 {
