$NetBSD: patch-Source_WebCore_Modules_webaudio_AudioContext.h,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WebCore/Modules/webaudio/AudioContext.h.orig	2013-05-08 08:53:03.000000000 +0000
+++ Source/WebCore/Modules/webaudio/AudioContext.h
@@ -333,7 +333,7 @@ private:
     enum { MaxNumberOfChannels = 32 };
 
     // Number of AudioBufferSourceNodes that are active (playing).
-    int m_activeSourceCount;
+    atomic_int m_activeSourceCount;
 };
 
 } // WebCore
