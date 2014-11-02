$NetBSD: patch-mozilla_security_manager_ssl_src_nsNSSComponent.cpp,v 1.3 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/security/manager/ssl/src/nsNSSComponent.cpp.orig	2014-10-14 06:36:36.000000000 +0000
+++ mozilla/security/manager/ssl/src/nsNSSComponent.cpp
@@ -53,6 +53,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
