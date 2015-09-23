$NetBSD: patch-security_manager_ssl_nsNSSComponent.cpp,v 1.1 2015/09/23 06:44:42 ryoon Exp $

--- security/manager/ssl/nsNSSComponent.cpp.orig	2015-08-24 21:53:20.000000000 +0000
+++ security/manager/ssl/nsNSSComponent.cpp
@@ -43,6 +43,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
