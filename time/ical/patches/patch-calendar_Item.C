$NetBSD: patch-calendar_Item.C,v 1.1 2013/01/09 17:22:14 is Exp $

--- calendar/item.C.orig	2009-07-28 19:09:43.000000000 +0000
+++ calendar/item.C
@@ -388,8 +388,8 @@ void Appointment::convert_tz(Date &d, in
     cache.from_d=d;
     cache.to_tz=to_tz;
 
-    const char* old=getenv("TZ");
-    if (old) old=strdupa(old);
+    char* old=getenv("TZ");
+    if (old) old=strdup(old);
 
     struct tm t;
     WeekDay wd;
@@ -427,6 +427,8 @@ void Appointment::convert_tz(Date &d, in
     min=t1->tm_min+t1->tm_hour*60;
     cache.to_d=d;
     cache.to_min=min;
+
+    if (old) free(old);
 }
 
 int Appointment::contains(Date d) const {
