$NetBSD: patch-time_Time.C,v 1.1 2013/01/09 17:22:14 is Exp $

--- time/Time.C.orig	2009-01-18 13:18:20.000000000 +0000
+++ time/Time.C
@@ -4,7 +4,6 @@
 #include <sys/types.h>
 #include <math.h>
 #include <string.h>
-#include <alloca.h>
 #include <stdlib.h>
 
 #include "config.h"
@@ -54,13 +53,13 @@ void Time::BreakDown(int& mday, WeekDay&
                      int& hour, int& min, int& sec, int& milli,
                      const char *tz) const
 {
-    const char *old;
+    char *old;
     if (! initialized) Initialize();
 
     time_t clock = (time_t) round(rep + offset);
 
     if (tz) {
-        if ((old=getenv("TZ"))) old=strdupa(old);
+        if ((old=getenv("TZ"))) old=strdup(old);
         setenv("TZ", tz, 1);
         tzset();
     }
@@ -80,6 +79,8 @@ void Time::BreakDown(int& mday, WeekDay&
     min   = t->tm_min;
     sec   = t->tm_sec;
     milli = (int)round((rep - floor(rep)) * 1000);
+
+    if(tz) free(old);
 }
 
 Time::Time(const struct timeval& tv) {
@@ -96,8 +97,8 @@ void Time::Convert(struct timeval& tv) c
 
 #if 0
 time_t timezone_to_local(time_t clock, const char *tz) {
-    const char *old=getenv("TZ");
-    if (old) old=strdupa(old);
+    char *old=getenv("TZ");
+    if (old) old=strdup(old);
     
     struct tm* t = localtime(&clock);
     setenv("TZ", tz, 1);
@@ -107,12 +108,13 @@ time_t timezone_to_local(time_t clock, c
     if (old) setenv("TZ", old, 1); else unsetenv("TZ");
     tzset();
 
+    if(old) free(old);
     return clock;
 }
 
 time_t local_to_timezone(time_t clock, const char *tz) {
-    const char *old=getenv("TZ");
-    if (old) old=strdupa(old);
+    char *old=getenv("TZ");
+    if (old) old=strdup(old);
     
     setenv("TZ", tz, 1);
     tzset();
@@ -122,6 +124,7 @@ time_t local_to_timezone(time_t clock, c
     tzset();
     clock = mktime(t);
 
+    if (old) free(old);
     return clock;
 }
 #endif
