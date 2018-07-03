$NetBSD: patch-django_contrib_admin_widgets.py,v 1.1 2018/07/03 06:42:27 adam Exp $

Fix syntax error (Python 3.7).

--- django/contrib/admin/widgets.py.orig	2018-07-03 06:33:30.000000000 +0000
+++ django/contrib/admin/widgets.py
@@ -149,7 +149,7 @@ class ForeignKeyRawIdWidget(forms.TextIn
             params = self.url_parameters()
             if params:
                 related_url += '?' + '&amp;'.join(
-                    '%s=%s' % (k, v) for k, v in params.items(),
+                    '%s=%s' % (k, v) for k, v in params.items()
                 )
             context['related_url'] = mark_safe(related_url)
             context['link_title'] = _('Lookup')
