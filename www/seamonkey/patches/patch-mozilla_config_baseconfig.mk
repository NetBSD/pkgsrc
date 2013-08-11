$NetBSD: patch-mozilla_config_baseconfig.mk,v 1.3 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/config/baseconfig.mk.orig	2013-08-04 03:05:18.000000000 +0000
+++ mozilla/config/baseconfig.mk
@@ -1,9 +1,9 @@
 INCLUDED_AUTOCONF_MK = 1
 
-includedir := $(includedir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-idldir = $(datadir)/idl/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-installdir = $(libdir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-sdkdir = $(libdir)/$(MOZ_APP_NAME)-devel-$(MOZ_APP_VERSION)
+includedir := $(includedir)/${MOZILLA_PKG_NAME}
+idldir = $(datadir)/idl/${MOZILLA_PKG_NAME}
+installdir = $(libdir)/${MOZILLA_PKG_NAME}
+sdkdir = $(libdir)/${MOZILLA_PKG_NAME}-sdk
 DIST = $(DEPTH)/dist
 
 # We do magic with OBJ_SUFFIX in config.mk, the following ensures we don't
