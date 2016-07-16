$NetBSD: patch-libs_kephal_service_xrandr12_randroutput.cpp,v 1.1 2016/07/16 00:47:00 markd Exp $

gcc6 fixes from opensuse

--- libs/kephal/service/xrandr12/randroutput.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ libs/kephal/service/xrandr12/randroutput.cpp
@@ -227,7 +227,7 @@ ModeList RandROutput::modes() const
 RandRMode RandROutput::mode() const
 {
     if (!isConnected())
-        return None;
+        return NULL;
 
     if (!m_crtc)
         return RandRMode();
