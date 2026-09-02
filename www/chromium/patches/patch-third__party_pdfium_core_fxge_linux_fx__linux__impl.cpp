$NetBSD: patch-third__party_pdfium_core_fxge_linux_fx__linux__impl.cpp,v 1.25 2026/09/02 13:13:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -18,7 +18,7 @@
 #include "core/fxge/fx_font.h"
 #include "core/fxge/systemfontinfo_iface.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS) && !BUILDFLAG(IS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -170,10 +170,9 @@ class CLinuxPlatform : public CFX_GEModu
         pInfo->AddPath(path);
       }
     } else {
-      pInfo->AddPath("/usr/share/fonts");
-      pInfo->AddPath("/usr/share/X11/fonts/Type1");
-      pInfo->AddPath("/usr/share/X11/fonts/TTF");
-      pInfo->AddPath("/usr/local/share/fonts");
+        pInfo->AddPath("@X11BASE@/lib/X11/fonts/Type1");
+        pInfo->AddPath("@X11BASE@/lib/X11/fonts/TTF");
+        pInfo->AddPath("@PREFIX@/share/fonts");
     }
     return pInfo;
   }
