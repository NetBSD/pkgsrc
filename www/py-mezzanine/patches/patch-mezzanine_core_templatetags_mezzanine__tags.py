$NetBSD: patch-mezzanine_core_templatetags_mezzanine__tags.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/core/templatetags/mezzanine_tags.py.orig	2016-11-05 04:09:20.000000000 +0000
+++ mezzanine/core/templatetags/mezzanine_tags.py
@@ -17,7 +17,7 @@ from django.core.files import File
 from django.core.files.storage import default_storage
 from django.core.urlresolvers import reverse, resolve, NoReverseMatch
 from django.db.models import Model
-from django.template import Context, Node, Template, TemplateSyntaxError
+from django.template import Node, Template, TemplateSyntaxError
 from django.template.base import (TOKEN_BLOCK, TOKEN_COMMENT,
                                   TOKEN_TEXT, TOKEN_VAR, TextNode)
 from django.template.defaultfilters import escape
@@ -106,11 +106,11 @@ def fields_for(context, form, template="
     Renders fields for a form with an optional template choice.
     """
     context["form_for_fields"] = form
-    return get_template(template).render(context)
+    return get_template(template).render(context.flatten())
 
 
-@register.inclusion_tag("includes/form_errors.html", takes_context=True)
-def errors_for(context, form):
+@register.inclusion_tag("includes/form_errors.html")
+def errors_for(form):
     """
     Renders an alert if the form has any errors.
     """
@@ -456,7 +456,7 @@ def editable_loader(context):
                                         context.get("page", None))
         template_vars["accounts_logout_url"] = context.get(
             "accounts_logout_url", None)
-        template_vars["toolbar"] = t.render(Context(template_vars))
+        template_vars["toolbar"] = t.render(template_vars)
         template_vars["richtext_media"] = RichTextField().formfield(
             ).widget.media
     return template_vars
@@ -510,7 +510,7 @@ def editable(parsed, context, token):
             context["editable_form"] = get_edit_form(obj, field_names)
             context["original"] = parsed
             t = get_template("includes/editable_form.html")
-            return t.render(context)
+            return t.render(context.flatten())
     return parsed
 
 
@@ -641,17 +641,14 @@ def admin_app_list(request):
     return app_list
 
 
-@register.inclusion_tag("admin/includes/dropdown_menu.html",
-                        takes_context=True)
+@register.inclusion_tag("admin/includes/dropdown_menu.html", takes_context=True)
 def admin_dropdown_menu(context):
     """
     Renders the app list for the admin dropdown menu navigation.
     """
-    template_vars = context.flatten()
     user = context["request"].user
     if user.is_staff:
-        template_vars["dropdown_menu_app_list"] = admin_app_list(
-            context["request"])
+        context["dropdown_menu_app_list"] = admin_app_list(context["request"])
         if user.is_superuser:
             sites = Site.objects.all()
         else:
@@ -659,11 +656,9 @@ def admin_dropdown_menu(context):
                 sites = user.sitepermissions.sites.all()
             except ObjectDoesNotExist:
                 sites = Site.objects.none()
-        template_vars["dropdown_menu_sites"] = list(sites)
-        template_vars["dropdown_menu_selected_site_id"] = current_site_id()
-        template_vars["settings"] = context["settings"]
-        template_vars["request"] = context["request"]
-        return template_vars
+        context["dropdown_menu_sites"] = list(sites)
+        context["dropdown_menu_selected_site_id"] = current_site_id()
+        return context.flatten()
 
 
 @register.inclusion_tag("admin/includes/app_list.html", takes_context=True)
@@ -672,7 +667,7 @@ def app_list(context):
     Renders the app list for the admin dashboard widget.
     """
     context["dashboard_app_list"] = admin_app_list(context["request"])
-    return context
+    return context.flatten()
 
 
 @register.inclusion_tag("admin/includes/recent_actions.html",
@@ -681,7 +676,7 @@ def recent_actions(context):
     """
     Renders the recent actions list for the admin dashboard widget.
     """
-    return context
+    return context.flatten()
 
 
 @register.render_tag
