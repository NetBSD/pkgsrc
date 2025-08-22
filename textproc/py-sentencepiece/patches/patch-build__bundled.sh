$NetBSD: patch-build__bundled.sh,v 1.1 2025/08/22 17:29:00 wiz Exp $

Fix build with cmake 4.

--- build_bundled.sh.orig	2024-02-19 08:06:52.000000000 +0000
+++ build_bundled.sh
@@ -18,5 +18,5 @@ else
   SRC_DIR=./sentencepiece
 fi
 
-cmake ${SRC_DIR} -B ${BUILD_DIR} -DSPM_ENABLE_SHARED=OFF -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR}
+cmake ${SRC_DIR} -B ${BUILD_DIR} -DSPM_ENABLE_SHARED=OFF -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} -DCMAKE_POLICY_VERSION_MINIMUM=3.5
 cmake --build ${BUILD_DIR} --config Release --target install --parallel $(nproc)
