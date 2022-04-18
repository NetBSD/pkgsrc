$NetBSD: patch-src_3rdparty_chromium_content_zygote_zygote__linux.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/zygote/zygote_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -650,3 +651,4 @@ bool Zygote::HandleGetSandboxStatus(int 
 }
 
 }  // namespace content
+#endif
