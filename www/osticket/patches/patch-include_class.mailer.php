$NetBSD: patch-include_class.mailer.php,v 1.1 2025/06/30 14:34:15 hauke Exp $

The html2text conversion hard-wraps the mail body, rendering ticket
URLs unrecognizable to many MUAs.

--- include/class.mailer.php.orig	2025-06-25 13:43:16.397706426 +0000
+++ include/class.mailer.php
@@ -516,7 +516,7 @@ class Mailer {
                         $body);
             }
 
-            $txtbody = rtrim(\Format::html2text($body, 90, false))
+            $txtbody = rtrim(\Format::html2text($body, 100, false))
                 . ($messageId ? "\nRef-Mid: $messageId\n" : '');
             $message->setTextBody($txtbody);
         }
