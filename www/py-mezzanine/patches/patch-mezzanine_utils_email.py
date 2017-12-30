$NetBSD: patch-mezzanine_utils_email.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/utils/email.py.orig	2016-01-17 01:21:39.000000000 +0000
+++ mezzanine/utils/email.py
@@ -4,7 +4,7 @@ from future.builtins import bytes, str
 from django.contrib.auth.tokens import default_token_generator
 from django.core.mail import EmailMultiAlternatives
 from django.core.urlresolvers import reverse
-from django.template import loader, Context
+from django.template import loader
 from django.utils.http import int_to_base36
 
 from mezzanine.conf import settings
@@ -25,7 +25,7 @@ def subject_template(template, context):
     Loads and renders an email subject template, returning the
     subject string.
     """
-    subject = loader.get_template(template).render(Context(context))
+    subject = loader.get_template(template).render(context)
     return " ".join(subject.splitlines()).strip()
 
 
@@ -55,7 +55,7 @@ def send_mail_template(subject, template
         addr_bcc = [addr_bcc]
     # Loads a template passing in vars as context.
     render = lambda type: loader.get_template("%s.%s" %
-                          (template, type)).render(Context(context))
+                          (template, type)).render(context)
     # Create and send email.
     msg = EmailMultiAlternatives(subject, render("txt"),
                                  addr_from, addr_to, addr_bcc,
