$NetBSD: patch-test_xi2_protocol-xigetclientpointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- test/xi2/protocol-xigetclientpointer.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ test/xi2/protocol-xigetclientpointer.c
@@ -124,6 +124,11 @@ test_XIGetClientPointer(void)
     request.win = INVALID_WINDOW_ID;
     request_XIGetClientPointer(&client_request, &request, BadWindow);
 
+    printf("Testing invalid length\n");
+    client_request.req_len -= 4;
+    request_XIGetClientPointer(&client_request, &request, BadLength);
+    client_request.req_len += 4;
+
     test_data.cp_is_set = FALSE;
 
     printf("Testing window None, unset ClientPointer.\n");
