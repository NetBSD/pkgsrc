$NetBSD: patch-flask__sendmail_message.py,v 1.2 2021/09/03 14:38:50 khorben Exp $

Fix for Python 3

From commit cc55636201554d1cf8516bb5bf0326bb498d03a7 in the flask-sendmail-ng
fork at https://github.com/ncrocfer/flask-sendmail-ng.

--- flask_sendmail/message.py.orig	2012-04-23 02:41:10.000000000 +0000
+++ flask_sendmail/message.py
@@ -1,3 +1,4 @@
+import sys
 from email.mime.text import MIMEText
 
 try:
@@ -99,7 +100,11 @@ class Message(object):
         if self.reply_to:
             msg['Reply-To'] = self.reply_to
 
-        return msg.as_string()
+        msg_str = msg.as_string()
+        if sys.version_info >= (3,0) and isinstance(msg_str, str):
+            return msg_str.encode(getattr(self, 'charset', 'utf-8'))
+        else:
+            return msg_str
 
     def send(self, connection):
         """
