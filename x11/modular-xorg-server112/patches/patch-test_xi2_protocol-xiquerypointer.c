$NetBSD: patch-test_xi2_protocol-xiquerypointer.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- test/xi2/protocol-xiquerypointer.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ test/xi2/protocol-xiquerypointer.c
@@ -200,6 +200,10 @@ test_XIQueryPointer(void)
     test_data.dev = devices.mouse;
     request.deviceid = devices.mouse->id;
     request_XIQueryPointer(&client_request, &request, Success);
+
+    /* test REQUEST_SIZE_MATCH */
+    client_request.req_len -= 4;
+    request_XIQueryPointer(&client_request, &request, BadLength);
 }
 
 int
