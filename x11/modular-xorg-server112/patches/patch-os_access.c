$NetBSD: patch-os_access.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- os/access.c.orig	2012-05-17 17:09:04.000000000 +0000
+++ os/access.c
@@ -1331,6 +1331,10 @@ GetHosts(pointer *data, int *pnHosts, in
     for (host = validhosts; host; host = host->next) {
         nHosts++;
         n += pad_to_int32(host->len) + sizeof(xHostEntry);
+        /* Could check for INT_MAX, but in reality having more than 1mb of
+           hostnames in the access list is ridiculous */
+        if (n >= 1048576)
+            break;
     }
     if (n) {
         *data = ptr = malloc(n);
@@ -1339,6 +1343,8 @@ GetHosts(pointer *data, int *pnHosts, in
         }
         for (host = validhosts; host; host = host->next) {
             len = host->len;
+            if ((ptr + sizeof(xHostEntry) + len) > ((unsigned char *) *data + n))
+                break;
             ((xHostEntry *) ptr)->family = host->family;
             ((xHostEntry *) ptr)->length = len;
             ptr += sizeof(xHostEntry);
