$NetBSD: patch-test_xi2_protocol-xipassivegrabdevice.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- test/xi2/protocol-xipassivegrabdevice.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ test/xi2/protocol-xipassivegrabdevice.c
@@ -137,6 +137,7 @@ request_XIPassiveGrabDevice(ClientPtr cl
     int rc;
     int modifiers;
 
+    client_request.req_len = req->length;
     rc = ProcXIPassiveGrabDevice(&client_request);
     assert(rc == error);
 
@@ -187,6 +188,13 @@ test_XIPassiveGrabDevice(void)
     request_XIPassiveGrabDevice(&client_request, request, BadDevice,
                                 request->deviceid);
 
+    printf("Testing invalid length\n");
+    request->length -= 2;
+    request_XIPassiveGrabDevice(&client_request, request, BadLength,
+                                client_request.errorValue);
+    /* re-init request since swapped length test leaves some values swapped */
+    request_init(request, XIPassiveGrabDevice);
+    request->grab_window = CLIENT_WINDOW_ID;
     request->deviceid = XIAllMasterDevices;
 
     printf("Testing invalid grab types\n");
