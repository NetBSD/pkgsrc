$NetBSD: patch-src_AsciiSrc.c,v 1.2 2022/04/04 12:55:28 wiz Exp $

Fix ctype(3) abuse.
https://gitlab.freedesktop.org/xorg/lib/libxaw/-/merge_requests/11

--- src/AsciiSrc.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/AsciiSrc.c
@@ -857,8 +857,8 @@ Search(Widget w, register XawTextPositio
 	/*CONSTCOND*/
 	while (1) {
 	    if (*ptr++ == c
-		|| (case_sensitive && isalpha(c) && isalpha(ptr[-1])
-		    && toupper(c) == toupper(ptr[-1]))) {
+		|| (case_sensitive && isalpha((unsigned char)c) && isalpha((unsigned char)ptr[-1])
+		    && toupper((unsigned char)c) == toupper((unsigned char)ptr[-1]))) {
 		if (++count == text->length)
 		    break;
 		c = *++str;
@@ -904,8 +904,8 @@ Search(Widget w, register XawTextPositio
 	/*CONSTCOND*/
 	while (1) {
 	    if (*ptr-- == c
-		|| (case_sensitive && isalpha(c) && isalpha(ptr[1])
-		    && toupper(c) == toupper(ptr[1]))) {
+		|| (case_sensitive && isalpha((unsigned char)c) && isalpha((unsigned char)ptr[1])
+		    && toupper((unsigned char)c) == toupper((unsigned char)ptr[1]))) {
 		if (++count == text->length)
 		    break;
 		c = *--str;
