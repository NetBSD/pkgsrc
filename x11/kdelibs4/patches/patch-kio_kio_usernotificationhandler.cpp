$NetBSD: patch-kio_kio_usernotificationhandler.cpp,v 1.1.2.2 2014/07/26 07:19:59 tron Exp $

http://quickgit.kde.org/?p=kdelibs.git&a=commitdiff&h=bbae87dc1be3ae063796a582774bd5642cacdd5d
Don't require a job to handle messageboxes.
http://www.kde.org/info/security/advisory-20140618-1.txt

--- kio/kio/usernotificationhandler.cpp.orig	2014-01-02 19:26:52.000000000 +0000
+++ kio/kio/usernotificationhandler.cpp
@@ -20,6 +20,7 @@
 
 #include "slave.h"
 #include "job_p.h"
+#include "jobuidelegate.h"
 
 #include <kdebug.h>
 
@@ -76,19 +77,18 @@ void UserNotificationHandler::processReq
 
         if (m_cachedResults.contains(key)) {
             result = *(m_cachedResults[key]);
-        } else if (r->slave->job()) {
-            SimpleJobPrivate* jobPrivate = SimpleJobPrivate::get(r->slave->job());
-            if (jobPrivate) {
-                result = jobPrivate->requestMessageBox(r->type,
-                                                      r->data.value(MSG_TEXT).toString(),
-                                                      r->data.value(MSG_CAPTION).toString(),
-                                                      r->data.value(MSG_YES_BUTTON_TEXT).toString(),
-                                                      r->data.value(MSG_NO_BUTTON_TEXT).toString(),
-                                                      r->data.value(MSG_YES_BUTTON_ICON).toString(),
-                                                      r->data.value(MSG_NO_BUTTON_ICON).toString(),
-                                                      r->data.value(MSG_DONT_ASK_AGAIN).toString(),
-                                                      r->data.value(MSG_META_DATA).toMap());
-            }
+        } else {
+            JobUiDelegate ui;
+            const JobUiDelegate::MessageBoxType type = static_cast<JobUiDelegate::MessageBoxType>(r->type);
+            result = ui.requestMessageBox(type,
+                                          r->data.value(MSG_TEXT).toString(),
+                                          r->data.value(MSG_CAPTION).toString(),
+                                          r->data.value(MSG_YES_BUTTON_TEXT).toString(),
+                                          r->data.value(MSG_NO_BUTTON_TEXT).toString(),
+                                          r->data.value(MSG_YES_BUTTON_ICON).toString(),
+                                          r->data.value(MSG_NO_BUTTON_ICON).toString(),
+                                          r->data.value(MSG_DONT_ASK_AGAIN).toString(),
+                                          r->data.value(MSG_META_DATA).toMap());
             m_cachedResults.insert(key, new int(result));
         }
     } else {
