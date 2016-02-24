$NetBSD: patch-kcontrol_info_info__osx.cpp,v 1.1 2016/02/24 10:14:11 jperkin Exp $

Fix build against newer CoreAudio.

--- kcontrol/info/info_osx.cpp.orig	2005-10-10 15:03:43.000000000 +0000
+++ kcontrol/info/info_osx.cpp
@@ -43,7 +43,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#include <iostream.h>
+#include <iostream>
 
 #include <qdict.h>
 #include <qfile.h>
@@ -117,7 +117,11 @@ bool GetInfo_Sound (QListView *lBox)
 #define kMaxStringSize 1024
 	OSStatus status;
 	AudioDeviceID gOutputDeviceID;
+#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 >= 1050
+	UInt32 propertySize;
+#else
 	unsigned long propertySize;
+#endif
 	char deviceName[kMaxStringSize];
 	char manufacturer[kMaxStringSize];
 	propertySize = sizeof(gOutputDeviceID);
