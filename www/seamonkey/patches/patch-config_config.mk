$NetBSD: patch-config_config.mk,v 1.1 2013/12/26 13:17:37 ryoon Exp $

From
http://www.openbsd.org/cgi-bin/cvsweb/ports/www/seamonkey/patches/patch-config_config_mk?rev=1.1

Fix fallout from http://hg.mozilla.org/releases/comm-release/rev/a6ab55f00e21
XPIDL_LINK being undefined breaks enigmail build

--- config/config.mk.orig	2013-12-11 04:19:54.000000000 +0000
+++ config/config.mk
@@ -325,6 +325,7 @@ MY_RULES	:= $(DEPTH)/config/myrules.mk
 # Default command macros; can be overridden in <arch>.mk.
 #
 CCC		= $(CXX)
+XPIDL_LINK = $(PYTHON) $(LIBXUL_DIST)/sdk/bin/xpt.py link
 
 OS_INCLUDES += $(NSPR_CFLAGS) $(NSS_CFLAGS) $(MOZ_JPEG_CFLAGS) $(MOZ_PNG_CFLAGS) $(MOZ_ZLIB_CFLAGS)
 
