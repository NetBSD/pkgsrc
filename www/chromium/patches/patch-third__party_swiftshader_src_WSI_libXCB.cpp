$NetBSD: patch-third__party_swiftshader_src_WSI_libXCB.cpp,v 1.13 2025/12/23 13:22:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/src/WSI/libXCB.cpp.orig	2025-12-17 23:05:18.000000000 +0000
+++ third_party/swiftshader/src/WSI/libXCB.cpp
@@ -57,7 +57,7 @@ LibXcbExports *LibXCB::loadExports()
 		}
 		else
 		{
-			libxcb = loadLibrary("libxcb.so.1");
+			libxcb = loadLibrary("libxcb.so");
 		}
 
 		if(getProcAddress(RTLD_DEFAULT, "xcb_shm_query_version"))  // Search the global scope for pre-loaded XCB library.
@@ -66,7 +66,7 @@ LibXcbExports *LibXCB::loadExports()
 		}
 		else
 		{
-			libshm = loadLibrary("libxcb-shm.so.0");
+			libshm = loadLibrary("libxcb-shm.so");
 		}
 
 		return LibXcbExports(libxcb, libshm);
