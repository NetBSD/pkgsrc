$NetBSD: patch-security_manager_ssl_src_nsNSSComponent.cpp,v 1.3 2014/02/08 09:36:00 ryoon Exp $

--- security/manager/ssl/src/nsNSSComponent.cpp.orig	2014-01-28 04:04:01.000000000 +0000
+++ security/manager/ssl/src/nsNSSComponent.cpp
@@ -53,6 +53,7 @@
 
 #include "nss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secmime.h"
