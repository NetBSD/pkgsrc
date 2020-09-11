$NetBSD: patch-Source_WebCore_Scripts_generate-unified-sources.sh,v 1.2 2020/09/11 14:47:35 leot Exp $

Avoid unportable `==' test(1) operator.

--- Source/WebCore/Scripts/generate-unified-sources.sh.orig	2020-08-12 09:17:55.000000000 +0000
+++ Source/WebCore/Scripts/generate-unified-sources.sh
@@ -7,7 +7,7 @@ ARGS=("$@")
 cd $SRCROOT
 
 if [ -z "${BUILD_SCRIPTS_DIR}" ]; then
-    if [ "${DEPLOYMENT_LOCATION}" == "YES" ]; then
+    if [ "${DEPLOYMENT_LOCATION}" = "YES" ]; then
         BUILD_SCRIPTS_DIR="${SDKROOT}${WK_ALTERNATE_WEBKIT_SDK_PATH}/usr/local/include/wtf/Scripts"
     else
         BUILD_SCRIPTS_DIR="${BUILT_PRODUCTS_DIR}/usr/local/include/wtf/Scripts"
@@ -22,7 +22,7 @@ if [ $# -eq 0 ]; then
 fi
 
 SOURCES="Sources.txt SourcesCocoa.txt"
-if [ "${USE_INTERNAL_SDK}" == "YES" ]; then
+if [ "${USE_INTERNAL_SDK}" = "YES" ]; then
     SOURCES="${SOURCES} SourcesCocoaInternalSDK.txt"
 fi
 
