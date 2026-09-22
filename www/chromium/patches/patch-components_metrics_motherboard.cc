$NetBSD: patch-components_metrics_motherboard.cc,v 1.26 2026/09/22 13:41:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/motherboard.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/metrics/motherboard.cc
@@ -1,6 +1,7 @@
 // Copyright 2022 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+// CHECK
 
 #include "components/metrics/motherboard.h"
 
