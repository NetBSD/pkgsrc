$NetBSD: patch-Source_WebCore_Modules_webaudio_AudioNode.h,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WebCore/Modules/webaudio/AudioNode.h.orig	2013-05-08 08:53:26.000000000 +0000
+++ Source/WebCore/Modules/webaudio/AudioNode.h
@@ -178,8 +178,8 @@ private:
     double m_lastNonSilentTime;
 
     // Ref-counting
-    volatile int m_normalRefCount;
-    volatile int m_connectionRefCount;
+    atomic_int m_normalRefCount;
+    atomic_int m_connectionRefCount;
     
     bool m_isMarkedForDeletion;
     bool m_isDisabled;
