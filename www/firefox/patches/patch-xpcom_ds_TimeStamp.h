$NetBSD: patch-xpcom_ds_TimeStamp.h,v 1.4 2014/10/15 13:07:07 ryoon Exp $

http://gnats.netbsd.org/47233

--- xpcom/ds/TimeStamp.h.orig	2014-10-11 09:06:50.000000000 +0000
+++ xpcom/ds/TimeStamp.h
@@ -199,14 +199,12 @@ private:
   {
     // NOTE: this MUST be a >= test, because int64_t(double(INT64_MAX))
     // overflows and gives INT64_MIN.
-    if (aTicks >= double(INT64_MAX)) {
-      return TimeDuration::FromTicks(INT64_MAX);
-    }
+    if (aTicks >= double(INT64_MAX))
+      return TimeDuration::FromTicks(int64_t(INT64_MAX));
 
     // This MUST be a <= test.
-    if (aTicks <= double(INT64_MIN)) {
-      return TimeDuration::FromTicks(INT64_MIN);
-    }
+    if (aTicks <= double(INT64_MIN))
+      return TimeDuration::FromTicks(int64_t(INT64_MIN));
 
     return TimeDuration::FromTicks(int64_t(aTicks));
   }
