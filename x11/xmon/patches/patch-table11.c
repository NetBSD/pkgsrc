$NetBSD: patch-table11.c,v 1.1 2026/06/20 11:13:44 nia Exp $

Avoid implicit int, which recent GCC versions no longer like.

--- table11.c.orig	2026-06-20 11:10:50.362786795 +0000
+++ table11.c
@@ -133,6 +133,8 @@ DefineValues(type, value, length, ctype, name)
 DefineValues(type, value, length, ctype, name)
 	TYPE type;
 	long	value;
+	int length;
+	int ctype;
 	char   *name;
 {
     ValueListEntryType  *p;
