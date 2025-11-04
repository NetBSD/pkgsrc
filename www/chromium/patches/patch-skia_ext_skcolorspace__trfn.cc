$NetBSD: patch-skia_ext_skcolorspace__trfn.cc,v 1.9 2025/11/04 14:55:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/skcolorspace_trfn.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ skia/ext/skcolorspace_trfn.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <array>
