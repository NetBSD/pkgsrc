$NetBSD: patch-mozilla_security_manager_ssl_src_nsNSSComponent.cpp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/security/manager/ssl/src/nsNSSComponent.cpp.orig	2013-05-03 03:08:10.000000000 +0000
+++ mozilla/security/manager/ssl/src/nsNSSComponent.cpp
@@ -72,6 +72,7 @@
 #include "nss.h"
 #include "pk11func.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "sechash.h"
