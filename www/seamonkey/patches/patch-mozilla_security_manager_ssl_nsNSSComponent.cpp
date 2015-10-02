$NetBSD: patch-mozilla_security_manager_ssl_nsNSSComponent.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/security/manager/ssl/nsNSSComponent.cpp.orig	2015-09-25 07:36:25.000000000 +0000
+++ mozilla/security/manager/ssl/nsNSSComponent.cpp
@@ -43,6 +43,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
