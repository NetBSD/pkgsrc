$NetBSD: patch-security_nss_lib_smime_config.mk,v 1.1 2013/03/24 16:45:55 joerg Exp $

--- security/nss/lib/smime/config.mk.orig	2013-03-24 14:47:55.000000000 +0000
+++ security/nss/lib/smime/config.mk
@@ -92,3 +92,4 @@ ifeq ($(OS_TARGET),SunOS)
 MKSHLIB += -R '$$ORIGIN'
 endif
 
+MKSHLIB += -Wl,-rpath,${PREFIX}/lib/nvu-1.0
