$NetBSD: patch-flask__sendmail_connection.py,v 1.2 2021/06/02 21:06:03 khorben Exp $

Do not send messages when testing or disabled in configuration

Submitted upstream in PR #12 (at
https://github.com/ajford/flask-sendmail/pull/12).

--- flask_sendmail/connection.py.orig	2012-04-23 02:11:53.000000000 +0000
+++ flask_sendmail/connection.py
@@ -18,6 +18,9 @@ class Connection(object):
         pass
 
     def send(self, message):
+        if self.suppress:
+            return 0
+
         sm = Popen([self.mail.mailer, self.mail.mailer_flags], stdin=PIPE,
                    stdout=PIPE, stderr=STDOUT)
         sm.stdin.write(message.dump())
