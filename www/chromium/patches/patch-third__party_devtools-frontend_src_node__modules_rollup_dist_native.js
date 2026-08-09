$NetBSD: patch-third__party_devtools-frontend_src_node__modules_rollup_dist_native.js,v 1.10 2026/08/09 06:31:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/devtools-frontend/src/node_modules/rollup/dist/native.js.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/devtools-frontend/src/node_modules/rollup/dist/native.js
@@ -57,8 +57,16 @@ const bindingsByPlatformAndArch = {
 		x64: { base: 'darwin-x64' }
 	},
 	freebsd: {
-		arm64: { base: 'freebsd-arm64' },
-		x64: { base: 'freebsd-x64' }
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
 	},
 	linux: {
 		arm: { base: 'linux-arm-gnueabihf', musl: 'linux-arm-musleabihf' },
@@ -69,9 +77,6 @@ const bindingsByPlatformAndArch = {
 		s390x: { base: 'linux-s390x-gnu', musl: null },
 		x64: { base: 'linux-x64-gnu', musl: 'linux-x64-musl' }
 	},
-	openbsd: {
-		x64: { base: 'openbsd-x64' }
-	},
 	openharmony: {
 		arm64: { base: 'openharmony-arm64' }
 	},
