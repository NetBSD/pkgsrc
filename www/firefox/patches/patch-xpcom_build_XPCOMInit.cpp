$NetBSD: patch-xpcom_build_XPCOMInit.cpp,v 1.1 2015/01/16 22:42:09 ryoon Exp $

--- xpcom/build/XPCOMInit.cpp.orig	2015-01-09 04:38:29.000000000 +0000
+++ xpcom/build/XPCOMInit.cpp
@@ -139,7 +139,9 @@ extern nsresult nsStringInputStreamConst
 #include "mozilla/VisualEventTracer.h"
 #endif
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
 #include "ogg/ogg.h"
+#endif
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
 #include "vpx_mem/vpx_mem.h"
 #endif
@@ -652,11 +654,13 @@ NS_InitXPCOM2(nsIServiceManager** aResul
   // this oddness.
   mozilla::SetICUMemoryFunctions();
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
   // Do the same for libogg.
   ogg_set_mem_functions(OggReporter::CountingMalloc,
                         OggReporter::CountingCalloc,
                         OggReporter::CountingRealloc,
                         OggReporter::CountingFree);
+#endif
 
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
   // And for VPX.
