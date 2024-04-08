$NetBSD: patch-etc.c,v 1.1 2024/04/08 06:01:21 wiz Exp $

https://github.com/tats/w3m/pull/273

--- etc.c.orig	2023-01-21 02:01:52.000000000 +0000
+++ etc.c
@@ -393,7 +393,10 @@ checkType(Str s, Lineprop **oprop, Linec
 			    if (color)
 				color -= plen;
 #endif
-			    plen = *(--plens);
+			    if (plens == plens_buffer)
+				plen = 0;
+			    else
+				plen = *(--plens);
 			    str += 2;
 			}
 		    }
@@ -419,7 +422,10 @@ checkType(Str s, Lineprop **oprop, Linec
 			    if (color)
 				color -= plen;
 #endif
-			    plen = *(--plens);
+			    if (plens == plens_buffer)
+				plen = 0;
+			    else
+				plen = *(--plens);
 			    str++;
 			}
 #else
