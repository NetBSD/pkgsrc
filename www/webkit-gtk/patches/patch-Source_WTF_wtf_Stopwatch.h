$NetBSD: patch-Source_WTF_wtf_Stopwatch.h,v 1.1 2015/07/12 00:44:46 wiz Exp $

--- Source/WTF/wtf/Stopwatch.h.orig	2015-03-04 14:25:16.000000000 +0000
+++ Source/WTF/wtf/Stopwatch.h
@@ -44,7 +44,7 @@ public:
 
     double elapsedTime();
 
-    bool isActive() const { return !isnan(m_lastStartTime); }
+    bool isActive() const { return !std::isnan(m_lastStartTime); }
 private:
     Stopwatch() { reset(); }
 
@@ -60,14 +60,14 @@ inline void Stopwatch::reset()
 
 inline void Stopwatch::start()
 {
-    ASSERT_WITH_MESSAGE(isnan(m_lastStartTime), "Tried to start the stopwatch, but it is already running.");
+    ASSERT_WITH_MESSAGE(std::isnan(m_lastStartTime), "Tried to start the stopwatch, but it is already running.");
 
     m_lastStartTime = monotonicallyIncreasingTime();
 }
 
 inline void Stopwatch::stop()
 {
-    ASSERT_WITH_MESSAGE(!isnan(m_lastStartTime), "Tried to stop the stopwatch, but it is not running.");
+    ASSERT_WITH_MESSAGE(!std::isnan(m_lastStartTime), "Tried to stop the stopwatch, but it is not running.");
 
     m_elapsedTime += monotonicallyIncreasingTime() - m_lastStartTime;
     m_lastStartTime = NAN;
@@ -75,7 +75,7 @@ inline void Stopwatch::stop()
 
 inline double Stopwatch::elapsedTime()
 {
-    bool shouldSuspend = !isnan(m_lastStartTime);
+    bool shouldSuspend = !std::isnan(m_lastStartTime);
     if (shouldSuspend)
         stop();
 
