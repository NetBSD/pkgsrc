$NetBSD: patch-macosx_tkMacOSXInit.c,v 1.1 2014/10/31 21:11:18 adam Exp $

Fix for Mac crash on Yosemite because of changes in version checking,
see Tk Source Code Check-in [e49c25c711].

--- macosx/tkMacOSXInit.c.orig	2014-10-31 20:34:20.000000000 +0000
+++ macosx/tkMacOSXInit.c
@@ -236,7 +236,11 @@ TkpInit(
 	if (!uname(&name)) {
 	    tkMacOSXMacOSXVersion = (strtod(name.release, NULL) + 96) * 10;
 	}
-	if (tkMacOSXMacOSXVersion &&
+	/*Check for new versioning scheme on Yosemite (10.10) and later.*/
+	if (MAC_OS_X_VERSION_MIN_REQUIRED > 100000) {
+		tkMacOSXMacOSXVersion = MAC_OS_X_VERSION_MIN_REQUIRED/100;
+	}
+	if (tkMacOSXMacOSXVersion && MAC_OS_X_VERSION_MIN_REQUIRED < 100000 &&
 		tkMacOSXMacOSXVersion/10 < MAC_OS_X_VERSION_MIN_REQUIRED/10) {
 	    Tcl_Panic("Mac OS X 10.%d or later required !",
 		    (MAC_OS_X_VERSION_MIN_REQUIRED/10)-100);
