$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_platform_Timer.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

Upstream changeset 92556

--- src/3rdparty/webkit/Source/WebCore/platform/Timer.h.orig	2012-11-23 10:09:58.000000000 +0000
+++ src/3rdparty/webkit/Source/WebCore/platform/Timer.h
@@ -84,9 +84,9 @@ private:
     ThreadIdentifier m_thread;
 #endif
 
-    friend class TimerHeapElement;
     friend class ThreadTimers;
-    friend bool operator<(const TimerHeapElement&, const TimerHeapElement&);
+    friend class TimerHeapLessThanFunction;
+    friend class TimerHeapReference;
 };
 
 template <typename TimerFiredClass> class Timer : public TimerBase {
