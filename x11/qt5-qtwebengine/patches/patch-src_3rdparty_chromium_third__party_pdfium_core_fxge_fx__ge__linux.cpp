$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxge_fx__ge__linux.cpp,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp
@@ -16,7 +16,7 @@
 #include "core/fxge/systemfontinfo_iface.h"
 #include "third_party/base/stl_util.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS) && !defined(OS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -169,6 +169,7 @@ class CLinuxPlatform : public CFX_GEModu
       pInfo->AddPath("/usr/share/X11/fonts/Type1");
       pInfo->AddPath("/usr/share/X11/fonts/TTF");
       pInfo->AddPath("/usr/local/share/fonts");
+      pInfo->AddPath("@X11BASE@/share/fonts");
     }
     return pInfo;
   }
