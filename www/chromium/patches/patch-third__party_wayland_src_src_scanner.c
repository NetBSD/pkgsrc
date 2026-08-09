$NetBSD: patch-third__party_wayland_src_src_scanner.c,v 1.5 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/wayland/src/src/scanner.c.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/wayland/src/src/scanner.c
@@ -294,7 +294,7 @@ uppercase_dup(const char *src)
 
 	u = xstrdup(src);
 	for (i = 0; u[i]; i++)
-		u[i] = toupper(u[i]);
+		u[i] = toupper((unsigned char)u[i]);
 	u[i] = '\0';
 
 	return u;
@@ -354,7 +354,7 @@ desc_dump(char *desc, const char *fmt, .
 	for (i = 0; desc[i]; ) {
 		k = i;
 		newlines = 0;
-		while (desc[i] && isspace(desc[i])) {
+		while (desc[i] && isspace((unsigned char)desc[i])) {
 			if (desc[i] == '\n')
 				newlines++;
 			i++;
@@ -363,7 +363,7 @@ desc_dump(char *desc, const char *fmt, .
 			break;
 
 		j = i;
-		while (desc[i] && !isspace(desc[i]))
+		while (desc[i] && !isspace((unsigned char)desc[i]))
 			i++;
 
 		if (newlines > 1)
