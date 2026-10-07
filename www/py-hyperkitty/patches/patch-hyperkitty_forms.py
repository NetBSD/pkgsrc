$NetBSD: patch-hyperkitty_forms.py,v 1.1 2026/10/07 19:37:03 markd Exp $

Add tag widget now renders properly with Django 5.2.
https://gitlab.com/mailman/hyperkitty/-/commit/02a3ca5316431bc43fc6ed3fd30d297dfa3f1316

--- hyperkitty/forms.py.orig	2023-10-21 17:37:44.353938000 +0000
+++ hyperkitty/forms.py
@@ -21,6 +21,7 @@
 #
 
 from django import forms
+from django.utils.html import format_html
 from django.utils.safestring import mark_safe
 from django.utils.translation import gettext_lazy as _
 
@@ -37,13 +38,12 @@ class TextInputWithButton(forms.TextInpu
         button_text = self.attrs.pop("button_text", "")
         initial_rendering = forms.TextInput.render(
                 self, name, value, attrs, renderer=renderer)
-        button = mark_safe(
+        return format_html(
+            '<span class="input-append"><div class="input-group">{}'
             '<span class="input-group-btn"><button type="submit" '
-            'class="btn btn-outline-primary">%s</button></span>'
-            % button_text)
-        return "".join([
-            '<span class="input-append"><div class="input-group">',
-            initial_rendering, button, '</div></span>'])
+            'class="btn btn-outline-primary">{}</button></span>'
+            '</div></span>',
+            initial_rendering, button_text)
 
 
 class AddTagForm(forms.Form):
