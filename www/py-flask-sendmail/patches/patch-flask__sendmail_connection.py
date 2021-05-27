$NetBSD: patch-flask__sendmail_connection.py,v 1.1 2021/05/27 22:25:05 khorben Exp $

Fix type error when sending messages

--- flask_sendmail/connection.py.orig	2012-04-23 02:11:53.000000000 +0000
+++ flask_sendmail/connection.py
@@ -20,7 +20,7 @@ class Connection(object):
     def send(self, message):
         sm = Popen([self.mail.mailer, self.mail.mailer_flags], stdin=PIPE,
                    stdout=PIPE, stderr=STDOUT)
-        sm.stdin.write(message.dump())
+        sm.stdin.write(message.dump().encode())
         sm.communicate()
 
         return sm.returncode
