$NetBSD: patch-src_wl-paste.c,v 1.1 2026/04/15 07:49:39 kikadf Exp $

* Fix ctype usage

--- src/wl-paste.c.orig	2026-03-05 17:45:33.262067890 +0000
+++ src/wl-paste.c
@@ -139,7 +139,7 @@ static const char *mime_type_to_request(
             try_any_text;
         } else if (strchr(options.explicit_type, '/') != NULL) {
             try_explicit;
-        } else if (isupper(options.explicit_type[0])) {
+        } else if (isupper((unsigned char)options.explicit_type[0])) {
             try_explicit;
         } else {
             try_explicit;
