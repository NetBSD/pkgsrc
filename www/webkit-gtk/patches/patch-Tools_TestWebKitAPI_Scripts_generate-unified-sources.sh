$NetBSD: patch-Tools_TestWebKitAPI_Scripts_generate-unified-sources.sh,v 1.1 2019/09/10 22:10:04 leot Exp $

Avoid unportable `==' test(1) operator.

--- Tools/TestWebKitAPI/Scripts/generate-unified-sources.sh.orig	2019-08-28 11:46:33.000000000 +0000
+++ Tools/TestWebKitAPI/Scripts/generate-unified-sources.sh
@@ -7,7 +7,7 @@ ARGS=("$@")
 cd $SRCROOT
 
 if [ -z "${BUILD_SCRIPTS_DIR}" ]; then
-    if [ "${DEPLOYMENT_LOCATION}" == "YES" ]; then
+    if [ "${DEPLOYMENT_LOCATION}" = "YES" ]; then
         BUILD_SCRIPTS_DIR="${SDKROOT}${WK_ALTERNATE_WEBKIT_SDK_PATH}/usr/local/include/wtf/Scripts"
     else
         BUILD_SCRIPTS_DIR="${BUILT_PRODUCTS_DIR}/usr/local/include/wtf/Scripts"
