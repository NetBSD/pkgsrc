$NetBSD: patch-libtext_text.h,v 1.1 2012/05/04 20:13:48 joerg Exp $

--- libtext/text.h.orig	2012-04-28 21:27:52.000000000 +0000
+++ libtext/text.h
@@ -87,5 +87,6 @@ ulong			_backnl(Text *, long, ulong);
 
 ulong			texttoutf(char *, Rune *, Rune *);
 ulong			utftotext(Rune *, char *, char *);
+int			alnum(int);
 
 #endif
