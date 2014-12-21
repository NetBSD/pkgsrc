$NetBSD: patch-os_rpcauth.c,v 1.1 2014/12/21 16:03:17 wiz Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- os/rpcauth.c.orig	2012-05-17 17:09:04.000000000 +0000
+++ os/rpcauth.c
@@ -66,6 +66,10 @@ authdes_ezdecode(const char *inmsg, int 
     SVCXPRT xprt;
 
     temp_inmsg = malloc(len);
+    if (temp_inmsg == NULL) {
+        why = AUTH_FAILED; /* generic error, since there is no AUTH_BADALLOC */
+        return NULL;
+    }
     memmove(temp_inmsg, inmsg, len);
 
     memset((char *) &msg, 0, sizeof(msg));
