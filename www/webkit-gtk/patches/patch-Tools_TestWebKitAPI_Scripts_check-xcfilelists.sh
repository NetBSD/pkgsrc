$NetBSD: patch-Tools_TestWebKitAPI_Scripts_check-xcfilelists.sh,v 1.1 2019/09/10 22:10:04 leot Exp $

Avoid unportable `==' test(1) operator.

--- Tools/TestWebKitAPI/Scripts/check-xcfilelists.sh.orig	2019-08-28 11:46:33.000000000 +0000
+++ Tools/TestWebKitAPI/Scripts/check-xcfilelists.sh
@@ -1,8 +1,8 @@
 #!/bin/sh
 
-[ "${WK_DISABLE_CHECK_XCFILELISTS}" == "1" ] && { echo "### Not running because WK_DISABLE_CHECK_XCFILELISTS is set"; exit 0; }
-[ "${DEPLOYMENT_LOCATION}" == "YES" ] && { echo "### Not running because DEPLOYMENT_LOCATION is YES"; exit 0; }
-[ "${USE_INTERNAL_SDK}" == "YES" ] || { echo "### Not running because USE_INTERNAL_SDK is not YES"; exit 0; }
+[ "${WK_DISABLE_CHECK_XCFILELISTS}" = "1" ] && { echo "### Not running because WK_DISABLE_CHECK_XCFILELISTS is set"; exit 0; }
+[ "${DEPLOYMENT_LOCATION}" = "YES" ] && { echo "### Not running because DEPLOYMENT_LOCATION is YES"; exit 0; }
+[ "${USE_INTERNAL_SDK}" = "YES" ] || { echo "### Not running because USE_INTERNAL_SDK is not YES"; exit 0; }
 
 SCRIPT="${BUILD_SCRIPTS_DIR}/generate-xcfilelists"
 [ -f "${SCRIPT}" ] || SCRIPT="${PROJECT_DIR}/../../../${WK_ADDITIONAL_SCRIPTS_DIR}/generate-xcfilelists"
