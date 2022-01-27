$NetBSD: patch-conftest.py,v 1.1 2022/01/27 10:16:09 wiz Exp $

get_marker has been renamed to get_closest_marker.

--- conftest.py.orig	2018-12-15 19:00:21.000000000 +0000
+++ conftest.py
@@ -74,6 +74,6 @@ def user_instance(request, admin_user):
 
 @pytest.fixture(autouse=True)
 def has_git_requirements(request, project_root):
-    if request.node.get_marker('has_git_requirements'):
+    if request.node.get_closest_marker('has_git_requirements'):
         if not os.path.exists(os.path.join(project_root, '.git', 'refs', 'heads', 'master')):
             pytest.skip('skipped test as project is not a git repo')
