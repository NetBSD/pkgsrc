$NetBSD: patch-src_shell-util.c,v 1.1 2020/11/10 12:06:59 nia Exp $

Quick ugly fix, breaks time string translation/format

--- src/shell-util.c.orig	2020-10-05 18:36:07.971836800 +0000
+++ src/shell-util.c
@@ -154,18 +154,22 @@ shell_util_translate_time_string (const 
   locale_t old_loc;
   locale_t loc = (locale_t) 0;
 
+#ifndef __NetBSD__
   if (locale)
     loc = newlocale (LC_MESSAGES_MASK, locale, (locale_t) 0);
 
   old_loc = uselocale (loc);
+#endif
 
   sep = strchr (str, '\004');
   res = g_dpgettext (NULL, str, sep ? sep - str + 1 : 0);
 
+#ifndef __NetBSD__
   uselocale (old_loc);
 
   if (loc != (locale_t) 0)
     freelocale (loc);
+#endif
 
   return res;
 }
