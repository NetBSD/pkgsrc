$NetBSD: patch-js_xpconnect_src_XPCConvert.cpp,v 1.1 2015/03/31 10:59:43 martin Exp $

Suggested workaround for https://bugzilla.mozilla.org/show_bug.cgi?id=1147837
Avoids a crash on big endian 64 bit architectures.

--- js/xpconnect/src/XPCConvert.cpp.orig	2015-03-21 04:42:37.000000000 +0100
+++ js/xpconnect/src/XPCConvert.cpp	2015-03-30 13:49:16.000000000 +0200
@@ -134,7 +134,7 @@
         d.setNumber(*static_cast<const float*>(s));
         return true;
     case nsXPTType::T_DOUBLE:
-        d.setNumber(*static_cast<const double*>(s));
+        d.setNumber(CanonicalizeNaN(*static_cast<const double*>(s)));
         return true;
     case nsXPTType::T_BOOL  :
         d.setBoolean(*static_cast<const bool*>(s));
