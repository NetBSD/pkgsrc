$NetBSD: patch-ptyx.h,v 1.1 2014/09/22 11:56:54 joerg Exp $

--- ptyx.h.orig	2014-09-20 18:45:54.000000000 +0000
+++ ptyx.h
@@ -537,3 +537,6 @@ extern Cursor make_colored_cursor();
 extern int GetBytesAvailable();
 extern void first_map_occurred();
 extern int kill_process_group();
+
+void unparseputc(int, int);
+void unparseseq(ANSI *, int);
