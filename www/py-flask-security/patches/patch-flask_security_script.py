$NetBSD: patch-flask_security_script.py,v 1.1 2014/01/24 09:49:34 kleink Exp $

--- flask_security/script.py.orig	2013-07-22 18:36:22.000000000 +0200
+++ flask_security/script.py	2014-01-24 10:40:19.000000000 +0100
@@ -8,6 +8,8 @@
     :copyright: (c) 2012 by Matt Wright.
     :license: MIT, see LICENSE for more details.
 """
+from __future__ import print_function
+
 try:
     import simplejson as json
 except ImportError:
@@ -26,7 +28,7 @@ _datastore = LocalProxy(lambda: current_
 
 
 def pprint(obj):
-    print json.dumps(obj, sort_keys=True, indent=4)
+    print(json.dumps(obj, sort_keys=True, indent=4))
 
 
 def commit(fn):
@@ -59,11 +61,11 @@ class CreateUserCommand(Command):
         if form.validate():
             kwargs['password'] = encrypt_password(kwargs['password'])
             _datastore.create_user(**kwargs)
-            print 'User created successfully.'
+            print('User created successfully.')
             kwargs['password'] = '****'
             pprint(kwargs)
         else:
-            print 'Error creating user'
+            print('Error creating user')
             pprint(form.errors)
 
 
@@ -78,7 +80,7 @@ class CreateRoleCommand(Command):
     @commit
     def run(self, **kwargs):
         _datastore.create_role(**kwargs)
-        print 'Role "%(name)s" created successfully.' % kwargs
+        print('Role "%(name)s" created successfully.' % kwargs)
 
 
 class _RoleCommand(Command):
@@ -94,7 +96,7 @@ class AddRoleCommand(_RoleCommand):
     @commit
     def run(self, user_identifier, role_name):
         _datastore.add_role_to_user(user_identifier, role_name)
-        print "Role '%s' added to user '%s' successfully" % (role_name, user_identifier)
+        print("Role '%s' added to user '%s' successfully" % (role_name, user_identifier))
 
 
 class RemoveRoleCommand(_RoleCommand):
@@ -103,7 +105,7 @@ class RemoveRoleCommand(_RoleCommand):
     @commit
     def run(self, user_identifier, role_name):
         _datastore.remove_role_from_user(user_identifier, role_name)
-        print "Role '%s' removed from user '%s' successfully" % (role_name, user_identifier)
+        print("Role '%s' removed from user '%s' successfully" % (role_name, user_identifier))
 
 
 class _ToggleActiveCommand(Command):
@@ -118,7 +120,7 @@ class DeactivateUserCommand(_ToggleActiv
     @commit
     def run(self, user_identifier):
         _datastore.deactivate_user(user_identifier)
-        print "User '%s' has been deactivated" % user_identifier
+        print("User '%s' has been deactivated" % user_identifier)
 
 
 class ActivateUserCommand(_ToggleActiveCommand):
@@ -127,4 +129,4 @@ class ActivateUserCommand(_ToggleActiveC
     @commit
     def run(self, user_identifier):
         _datastore.activate_user(user_identifier)
-        print "User '%s' has been activated" % user_identifier
+        print("User '%s' has been activated" % user_identifier)
