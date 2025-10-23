$NetBSD: patch-src_Pager_Pager.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/Pager/Pager.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Pager/Pager.c
@@ -210,7 +210,7 @@ int main (int argc, char **argv)
 		LOCAL_DEBUG_OUT ("argv[%d] = \"%s\", original argv[%d] = \"%s\"", i,
 										 argv[i], i, MyArgs.saved_argv[i]);
 		if (argv[i] != NULL) {
-			if (isdigit (argv[i][0])) {
+			if (isdigit ((unsigned char)argv[i][0])) {
 				++desk_cnt;
 				if (desk_cnt == 1)
 					desk1 = atoi (argv[i]);
