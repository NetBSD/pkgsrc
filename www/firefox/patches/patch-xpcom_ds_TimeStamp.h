$NetBSD: patch-xpcom_ds_TimeStamp.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

http://gnats.netbsd.org/47233

--- xpcom/ds/TimeStamp.h.orig	2014-01-28 04:04:07.000000000 +0000
+++ xpcom/ds/TimeStamp.h
@@ -161,11 +161,11 @@ private:
     // NOTE: this MUST be a >= test, because int64_t(double(INT64_MAX))
     // overflows and gives INT64_MIN.
     if (aTicks >= double(INT64_MAX))
-      return TimeDuration::FromTicks(INT64_MAX);
+      return TimeDuration::FromTicks(int64_t(INT64_MAX));
 
     // This MUST be a <= test.
     if (aTicks <= double(INT64_MIN))
-      return TimeDuration::FromTicks(INT64_MIN);
+      return TimeDuration::FromTicks(int64_t(INT64_MIN));
 
     return TimeDuration::FromTicks(int64_t(aTicks));
   }
