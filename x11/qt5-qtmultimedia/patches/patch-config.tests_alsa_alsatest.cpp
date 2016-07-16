$NetBSD: patch-config.tests_alsa_alsatest.cpp,v 1.1 2016/07/16 00:37:45 markd Exp $

Allow newer Alsa versions.

--- config.tests/alsa/alsatest.cpp.orig	2015-10-13 04:35:43.000000000 +0000
+++ config.tests/alsa/alsatest.cpp
@@ -32,7 +32,7 @@
 ****************************************************************************/
 
 #include <alsa/asoundlib.h>
-#if (!(SND_LIB_MAJOR == 1 && SND_LIB_MINOR == 0 && SND_LIB_SUBMINOR >= 10))
+#if (!(SND_LIB_MAJOR == 1 && SND_LIB_MINOR == 0 && SND_LIB_SUBMINOR >= 10) && !(SND_LIB_MAJOR == 1 && SND_LIB_MINOR >= 1))
 #error "Alsa version found too old, require >= 1.0.10"
 #endif
 
