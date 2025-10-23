$NetBSD: patch-libAfterBase_audit.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterBase/audit.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/audit.c
@@ -645,7 +645,7 @@ output_unfreed_mem (FILE *stream)
 						 if (ptr[i] == '\0')
 							 break;
 						 /* don't print strings containing non-space control characters or high ASCII */
-						 if ((ptr[i] <= 0x20 && !isspace (ptr[i])) || ptr[i] >= 0x80)
+						 if ((ptr[i] <= 0x20 && !isspace ((unsigned char)ptr[i])) || ptr[i] >= 0x80)
 							 i = m->length;
 					 }
 					 if (i < m->length)
