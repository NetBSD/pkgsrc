$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__service.cc,v 1.4 2026/10/16 15:30:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_service.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_service.cc
@@ -2,6 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
 #include "chrome/browser/private_verification_tokens/private_verification_tokens_service.h"
 
 #include <map>
@@ -587,3 +588,4 @@ void PrivateVerificationTokensService::O
     std::move(operation).Run();
   }
 }
+#endif
