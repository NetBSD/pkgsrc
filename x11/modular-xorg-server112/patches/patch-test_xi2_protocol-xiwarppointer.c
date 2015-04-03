$NetBSD: patch-test_xi2_protocol-xiwarppointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- test/xi2/protocol-xiwarppointer.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ test/xi2/protocol-xiwarppointer.c
@@ -197,6 +197,9 @@ test_XIWarpPointer(void)
     request_XIWarpPointer(&client_request, &request, Success);
 
     /* FIXME: src_x/y checks */
+
+    client_request.req_len -= 2; /* invalid length */
+    request_XIWarpPointer(&client_request, &request, BadLength);
 }
 
 int
