$NetBSD: patch-conv.c,v 1.1 2022/04/25 10:17:16 tnn Exp $

undo workarounds for old Solaris

--- conv.c.orig	2021-10-02 22:29:09.000000000 +0000
+++ conv.c
@@ -36,7 +36,7 @@ static int calcAgeInDays (const struct t
 // http://www.winehq.com/hypermail/wine-patches/2001/11/0024.html
 //
 // The following function was written by Francois Gouget.
-#ifdef SUN
+#ifdef OLD_SUN
 char* strsep (char** str, const char* delims)
 {
     if (!*str)		       // No more tokens
