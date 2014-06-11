$NetBSD: patch-xpcom_build_nsXPComInit.cpp,v 1.1 2014/06/11 00:41:36 ryoon Exp $

--- xpcom/build/nsXPComInit.cpp.orig	2014-05-29 23:31:50.000000000 +0000
+++ xpcom/build/nsXPComInit.cpp
@@ -128,7 +128,9 @@ extern nsresult nsStringInputStreamConst
 #include "mozilla/VisualEventTracer.h"
 #endif
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
 #include "ogg/ogg.h"
+#endif
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
 #include "vpx_mem/vpx_mem.h"
 #endif
@@ -564,11 +566,13 @@ NS_InitXPCOM2(nsIServiceManager* *result
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
