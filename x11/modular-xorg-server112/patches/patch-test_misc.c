$NetBSD: patch-test_misc.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- test/misc.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ test/misc.c
@@ -28,6 +28,8 @@
 #include <stdint.h>
 #include "misc.h"
 #include "scrnintstr.h"
+#include "dix.h"
+#include "dixstruct.h"
 
 ScreenInfo screenInfo;
 
@@ -155,11 +157,46 @@ dix_update_desktop_dimensions(void)
     assert_dimensions(-w2, -h2, w2, h2);
 }
 
+static int
+dix_request_fixed_size_overflow(ClientRec *client)
+{
+    xReq req = { 0 };
+
+    client->req_len = req.length = 1;
+    REQUEST_FIXED_SIZE(req, SIZE_MAX);
+    return Success;
+}
+
+static int
+dix_request_fixed_size_match(ClientRec *client)
+{
+    xReq req = { 0 };
+
+    client->req_len = req.length = 9;
+    REQUEST_FIXED_SIZE(req, 30);
+    return Success;
+}
+
+static void
+dix_request_size_checks(void)
+{
+    ClientRec client = { 0 };
+    int rc;
+
+    rc = dix_request_fixed_size_overflow(&client);
+    assert(rc == BadLength);
+
+    rc = dix_request_fixed_size_match(&client);
+    assert(rc == Success);
+}
+
+
 int
 main(int argc, char **argv)
 {
     dix_version_compare();
     dix_update_desktop_dimensions();
+    dix_request_size_checks();
 
     return 0;
 }
