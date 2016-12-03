$NetBSD: patch-xpcom_build_XPCOMInit.cpp,v 1.4 2016/12/03 09:58:26 ryoon Exp $

--- xpcom/build/XPCOMInit.cpp.orig	2016-10-31 20:15:39.000000000 +0000
+++ xpcom/build/XPCOMInit.cpp
@@ -137,7 +137,9 @@ extern nsresult nsStringInputStreamConst
 
 #include "mozilla/ipc/GeckoChildProcessHost.h"
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
 #include "ogg/ogg.h"
+#endif
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
 #if defined(HAVE_STDINT_H)
 // mozilla-config.h defines HAVE_STDINT_H, and then it's defined *again* in
@@ -638,11 +640,13 @@ NS_InitXPCOM2(nsIServiceManager** aResul
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
