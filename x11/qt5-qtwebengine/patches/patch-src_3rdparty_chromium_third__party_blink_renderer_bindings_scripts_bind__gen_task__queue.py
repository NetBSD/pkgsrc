$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_task__queue.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/task_queue.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/task_queue.py
@@ -2,6 +2,7 @@
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
+import functools
 import multiprocessing
 
 from .package_initializer import package_initializer
@@ -76,7 +77,7 @@ class TaskQueue(object):
         if not report_progress:
             return
 
-        done_count = reduce(
+        done_count = functools.reduce(
             lambda count, worker_task: count + bool(worker_task.ready()),
             self._worker_tasks, 0)
         report_progress(len(self._worker_tasks), done_count)
@@ -85,4 +86,4 @@ class TaskQueue(object):
 def _task_queue_run_tasks(tasks):
     for task in tasks:
         func, args, kwargs = task
-        apply(func, args, kwargs)
+        func(*args, **kwargs)
