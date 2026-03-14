$NetBSD: patch-third__party_devtools-frontend_src_node__modules_rollup_dist_native.js,v 1.2 2026/03/14 12:40:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/devtools-frontend/src/node_modules/rollup/dist/native.js.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/devtools-frontend/src/node_modules/rollup/dist/native.js
@@ -13,6 +13,18 @@ const bindingsByPlatformAndArch = {
 		arm64: { base: 'darwin-arm64' },
 		x64: { base: 'darwin-x64' }
 	},
+	freebsd: {
+		arm64: { base: 'freebsd' },
+		x64: { base: 'freebsd' }
+	},
+	openbsd: {
+		arm64: { base: 'openbsd' },
+		x64: { base: 'openbsd' }
+	},
+	netbsd: {
+		arm64: { base: 'netbsd' },
+		x64: { base: 'netbsd' }
+	},
 	linux: {
 		arm: { base: 'linux-arm-gnueabihf', musl: 'linux-arm-musleabihf' },
 		arm64: { base: 'linux-arm64-gnu', musl: 'linux-arm64-musl' },
