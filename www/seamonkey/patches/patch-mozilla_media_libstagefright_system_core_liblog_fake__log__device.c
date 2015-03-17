$NetBSD: patch-mozilla_media_libstagefright_system_core_liblog_fake__log__device.c,v 1.1 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/media/libstagefright/system/core/liblog/fake_log_device.c.orig	2015-03-09 05:34:24.000000000 +0000
+++ mozilla/media/libstagefright/system/core/liblog/fake_log_device.c
@@ -229,11 +229,11 @@ static void configureInitialState(const 
             char tagName[kMaxTagLen];
             int i, minPrio;
 
-            while (isspace(*tags))
+            while (isspace((unsigned char)*tags))
                 tags++;
 
             i = 0;
-            while (*tags != '\0' && !isspace(*tags) && *tags != ':' &&
+            while (*tags != '\0' && !isspace((unsigned char)*tags) && *tags != ':' &&
                 i < kMaxTagLen)
             {
                 tagName[i++] = *tags++;
@@ -272,7 +272,7 @@ static void configureInitialState(const 
                 }
 
                 tags++;
-                if (*tags != '\0' && !isspace(*tags)) {
+                if (*tags != '\0' && !isspace((unsigned char)*tags)) {
                     TRACE("ERROR: garbage in tag env; expected whitespace\n");
                     TRACE("       env='%s'\n", tags);
                     return;
