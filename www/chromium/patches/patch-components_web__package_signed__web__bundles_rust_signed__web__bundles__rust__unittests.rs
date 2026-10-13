$NetBSD: patch-components_web__package_signed__web__bundles_rust_signed__web__bundles__rust__unittests.rs,v 1.3 2026/10/13 13:16:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/web_package/signed_web_bundles/rust/signed_web_bundles_rust_unittests.rs.orig	2026-10-06 00:06:58.000000000 +0000
+++ components/web_package/signed_web_bundles/rust/signed_web_bundles_rust_unittests.rs
@@ -1,5 +0,0 @@
-// Copyright 2026 The Chromium Authors
-// Use of this source code is governed by a BSD-style license that can be
-// found in the LICENSE file.
-
-mod integrity_block_unittest;
