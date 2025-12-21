$NetBSD: patch-src_3rdparty_chromium_content_zygote_zygote__linux.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/zygote/zygote_linux.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #ifdef UNSAFE_BUFFERS_BUILD
 // TODO(crbug.com/342213636): Remove this and spanify to fix the errors.
@@ -723,3 +724,4 @@ void Zygote::HandleReinitializeLoggingRe
 }
 
 }  // namespace content
+#endif
