$NetBSD: patch-netwerk_protocol_http_Http2Session.cpp,v 1.7 2017/01/20 15:03:37 ryoon Exp $

Fix an insecure connection error with NSS 3.28 or later in HTTP2 case
https://hg.mozilla.org/mozilla-central/rev/361ac226da2a

--- netwerk/protocol/http/Http2Session.cpp.orig	2016-10-31 20:15:27.000000000 +0000
+++ netwerk/protocol/http/Http2Session.cpp
@@ -3542,8 +3542,8 @@ Http2Session::ConfirmTLSProfile()
     LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to DH %d < 2048\n",
           this, keybits));
     RETURN_SESSION_ERROR(this, INADEQUATE_SECURITY);
-  } else if (kea == ssl_kea_ecdh && keybits < 256) { // 256 bits is "security level" of 128
-    LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to ECDH %d < 256\n",
+  } else if (kea == ssl_kea_ecdh && keybits < 224) { // see rfc7540 9.2.1.
+    LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to ECDH %d < 224\n",
           this, keybits));
     RETURN_SESSION_ERROR(this, INADEQUATE_SECURITY);
   }
