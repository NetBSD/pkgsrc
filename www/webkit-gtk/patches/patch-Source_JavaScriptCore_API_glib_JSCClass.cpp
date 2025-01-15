$NetBSD: patch-Source_JavaScriptCore_API_glib_JSCClass.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/JavaScriptCore/API/glib/JSCClass.cpp.orig	2025-01-15 11:24:16.289034547 +0000
+++ Source/JavaScriptCore/API/glib/JSCClass.cpp
@@ -574,8 +574,8 @@ static GRefPtr<JSCValue> jscClassCreateC
  * jsc_class_add_constructor: (skip)
  * @jsc_class: a #JSCClass
  * @name: (nullable): the constructor name or %NULL
- * @callback: (scope async): a #GCallback to be called to create an instance of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to create an instance of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the constructor return value
  * @n_params: the number of parameter types to follow or 0 if constructor doesn't receive parameters.
@@ -623,8 +623,8 @@ JSCValue* jsc_class_add_constructor(JSCC
  * jsc_class_add_constructorv: (rename-to jsc_class_add_constructor)
  * @jsc_class: a #JSCClass
  * @name: (nullable): the constructor name or %NULL
- * @callback: (scope async): a #GCallback to be called to create an instance of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to create an instance of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the constructor return value
  * @n_parameters: the number of parameters
@@ -669,8 +669,8 @@ JSCValue* jsc_class_add_constructorv(JSC
  * jsc_class_add_constructor_variadic:
  * @jsc_class: a #JSCClass
  * @name: (nullable): the constructor name or %NULL
- * @callback: (scope async): a #GCallback to be called to create an instance of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to create an instance of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the constructor return value
  *
@@ -721,8 +721,8 @@ static void jscClassAddMethod(JSCClass* 
  * jsc_class_add_method: (skip)
  * @jsc_class: a #JSCClass
  * @name: the method name
- * @callback: (scope async): a #GCallback to be called to invoke method @name of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to invoke method @name of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the method return value, or %G_TYPE_NONE if the method is void.
  * @n_params: the number of parameter types to follow or 0 if the method doesn't receive parameters.
@@ -762,8 +762,8 @@ void jsc_class_add_method(JSCClass* jscC
  * jsc_class_add_methodv: (rename-to jsc_class_add_method)
  * @jsc_class: a #JSCClass
  * @name: the method name
- * @callback: (scope async): a #GCallback to be called to invoke method @name of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to invoke method @name of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the method return value, or %G_TYPE_NONE if the method is void.
  * @n_parameters: the number of parameter types to follow or 0 if the method doesn't receive parameters.
@@ -801,8 +801,8 @@ void jsc_class_add_methodv(JSCClass* jsc
  * jsc_class_add_method_variadic:
  * @jsc_class: a #JSCClass
  * @name: the method name
- * @callback: (scope async): a #GCallback to be called to invoke method @name of @jsc_class
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (scope async) (closure user_data): a #GCallback to be called to invoke method @name of @jsc_class
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  * @return_type: the #GType of the method return value, or %G_TYPE_NONE if the method is void.
  *
@@ -831,9 +831,9 @@ void jsc_class_add_method_variadic(JSCCl
  * @jsc_class: a #JSCClass
  * @name: the property name
  * @property_type: the #GType of the property value
- * @getter: (scope async) (nullable): a #GCallback to be called to get the property value
- * @setter: (scope async) (nullable): a #GCallback to be called to set the property value
- * @user_data: (closure): user data to pass to @getter and @setter
+ * @getter: (scope async) (closure user_data) (nullable): a #GCallback to be called to get the property value
+ * @setter: (scope async) (closure user_data) (nullable): a #GCallback to be called to set the property value
+ * @user_data: user data to pass to @getter and @setter
  * @destroy_notify: (nullable): destroy notifier for @user_data
  *
  * Add a property with @name to @jsc_class. When the property value needs to be getted, @getter is called
