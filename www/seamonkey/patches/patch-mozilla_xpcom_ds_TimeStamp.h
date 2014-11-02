$NetBSD: patch-mozilla_xpcom_ds_TimeStamp.h,v 1.2 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/xpcom/ds/TimeStamp.h.orig	2014-10-14 06:36:46.000000000 +0000
+++ mozilla/xpcom/ds/TimeStamp.h
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
