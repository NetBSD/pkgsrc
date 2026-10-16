$NetBSD: patch-components_web__package_signed__web__bundles_rust_signed__web__bundles__rust__unittests.rs,v 1.4 2026/10/16 15:30:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/web_package/signed_web_bundles/rust/signed_web_bundles_rust_unittests.rs.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/web_package/signed_web_bundles/rust/signed_web_bundles_rust_unittests.rs
@@ -1,5 +0,0 @@
-// Copyright 2026 The Chromium Authors
-// Use of this source code is governed by a BSD-style license that can be
-// found in the LICENSE file.
-
-mod integrity_block_unittest;
