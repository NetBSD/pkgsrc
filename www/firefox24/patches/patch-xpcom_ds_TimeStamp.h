$NetBSD: patch-xpcom_ds_TimeStamp.h,v 1.1 2013/11/03 04:52:00 ryoon Exp $

http://gnats.netbsd.org/47233

--- xpcom/ds/TimeStamp.h.orig	2013-01-04 23:44:47.000000000 +0000
+++ xpcom/ds/TimeStamp.h
@@ -130,11 +130,11 @@ private:
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
