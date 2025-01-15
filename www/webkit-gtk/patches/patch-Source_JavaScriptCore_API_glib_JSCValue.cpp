$NetBSD: patch-Source_JavaScriptCore_API_glib_JSCValue.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/JavaScriptCore/API/glib/JSCValue.cpp.orig	2025-01-15 11:28:27.077882718 +0000
+++ Source/JavaScriptCore/API/glib/JSCValue.cpp
@@ -1123,9 +1123,9 @@ static void jscValueObjectDefineProperty
  * @property_name: the name of the property to define
  * @flags: #JSCValuePropertyFlags
  * @property_type: the #GType of the property
- * @getter: (scope async) (nullable): a #GCallback to be called to get the property value
- * @setter: (scope async) (nullable): a #GCallback to be called to set the property value
- * @user_data: (closure): user data to pass to @getter and @setter
+ * @getter: (scope async) (closure user_data) (nullable): a #GCallback to be called to get the property value
+ * @setter: (scope async) (closure user_data) (nullable): a #GCallback to be called to set the property value
+ * @user_data: user data to pass to @getter and @setter
  * @destroy_notify: (nullable): destroy notifier for @user_data
  *
  * Define or modify a property with @property_name in object referenced by @value. When the
@@ -1178,8 +1178,8 @@ static GRefPtr<JSCValue> jscValueFunctio
  * jsc_value_new_function: (skip)
  * @context: a #JSCContext:
  * @name: (nullable): the function name or %NULL
- * @callback: (scope async): a #GCallback.
- * @user_data: (closure): user data to pass to @callback.
+ * @callback: (scope async) (closure user_data): a #GCallback.
+ * @user_data: user data to pass to @callback.
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the function return value, or %G_TYPE_NONE if the function is void.
  * @n_params: the number of parameter types to follow or 0 if the function doesn't receive parameters.
@@ -1219,8 +1219,8 @@ JSCValue* jsc_value_new_function(JSCCont
  * jsc_value_new_functionv: (rename-to jsc_value_new_function)
  * @context: a #JSCContext
  * @name: (nullable): the function name or %NULL
- * @callback: (scope async): a #GCallback.
- * @user_data: (closure): user data to pass to @callback.
+ * @callback: (scope async) (closure user_data): a #GCallback.
+ * @user_data: user data to pass to @callback.
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the function return value, or %G_TYPE_NONE if the function is void.
  * @n_parameters: the number of parameters
@@ -1258,8 +1258,8 @@ JSCValue* jsc_value_new_functionv(JSCCon
  * jsc_value_new_function_variadic:
  * @context: a #JSCContext
  * @name: (nullable): the function name or %NULL
- * @callback: (scope async): a #GCallback.
- * @user_data: (closure): user data to pass to @callback.
+ * @callback: (scope async) (closure user_data): a #GCallback.
+ * @user_data: user data to pass to @callback.
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the function return value, or %G_TYPE_NONE if the function is void.
  *
