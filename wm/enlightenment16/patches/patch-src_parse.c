$NetBSD: patch-src_parse.c,v 1.1 2025/10/29 23:50:00 gutteridge Exp $

Use ctype.h correctly.

--- src/parse.c.orig	2025-06-23 13:11:03.000000000 +0000
+++ src/parse.c
@@ -48,7 +48,7 @@ parse(char *buf, const char *fmt, ...)
         if (chf == '\0')
             break;
         /* Strip leading whitespace */
-        while (isspace(*buf))
+        while (isspace((unsigned char)*buf))
             buf++;
         if (!*buf)
             break;
@@ -67,7 +67,7 @@ parse(char *buf, const char *fmt, ...)
                     p = strchr(p, chq);
                     if (p)
                     {
-                        if (p[1] && !isspace(p[1]))
+                        if (p[1] && !isspace((unsigned char)p[1]))
                             continue;
                         *p++ = '\0';    /* Terminate at quote */
                     }
@@ -82,7 +82,7 @@ parse(char *buf, const char *fmt, ...)
             {
                 /* Token is unquoted */
                 p = buf + 1;
-                while (*p && !isspace(*p))
+                while (*p && !isspace((unsigned char)*p))
                     p++;
                 if (*p)
                     *p++ = '\0';
