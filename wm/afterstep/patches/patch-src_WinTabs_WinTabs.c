$NetBSD: patch-src_WinTabs_WinTabs.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/WinTabs/WinTabs.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/WinTabs/WinTabs.c
@@ -2545,7 +2545,7 @@ LOCAL_DEBUG_OUT ( "pattern = \"%s\"", ta
 
 		i = 0;
 		if (group->pattern_is_tail)
-			while (isspace (group->pattern[i])
+			while (isspace ((unsigned char)group->pattern[i])
 					|| group->pattern[i] == '-'
 					|| group->pattern[i] == ':' ) ++i;
 
@@ -2553,7 +2553,7 @@ LOCAL_DEBUG_OUT ( "pattern = \"%s\"", ta
 
 		i = group->pattern_length - i;
 		if (!group->pattern_is_tail)
-			while ( isspace(group_name[i])
+			while ( isspace((unsigned char)group_name[i])
 					|| group_name[i] == '-'
 					|| group_name[i] == ':'
 			       ) --i;
