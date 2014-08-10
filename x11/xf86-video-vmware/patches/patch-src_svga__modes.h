$NetBSD: patch-src_svga__modes.h,v 1.1 2014/08/10 09:08:21 wiz Exp $

Add 2560x1440 to supported resolutions.

Native resolution on iMac 27".
Reported missing by Benjamin Lorenz in
http://gnats.netbsd.org/49094

--- src/svga_modes.h.orig	2012-03-08 16:13:16.000000000 +0000
+++ src/svga_modes.h
@@ -28,6 +28,7 @@
    SVGA_DEFAULT_MODE(1280,  720) \
    SVGA_DEFAULT_MODE(1366,  768) \
    SVGA_DEFAULT_MODE(1920, 1080) \
+   SVGA_DEFAULT_MODE(2560, 1440) \
    /* 16:10 modes */ \
    SVGA_DEFAULT_MODE(1280,  800) \
    SVGA_DEFAULT_MODE(1440,  900) \
