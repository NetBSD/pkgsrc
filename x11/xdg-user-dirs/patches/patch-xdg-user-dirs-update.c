$NetBSD: patch-xdg-user-dirs-update.c,v 1.2 2016/02/23 11:31:54 jperkin Exp $

Fix build under Solaris 10 and Darwin 10.6.

--- xdg-user-dirs-update.c.orig	2013-06-26 15:38:46.000000000 +0000
+++ xdg-user-dirs-update.c
@@ -328,6 +328,24 @@ freev (char **strs)
     }
 }
 
+#if defined(__sun__) || (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
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
