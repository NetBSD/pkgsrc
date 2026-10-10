$NetBSD: patch-lib_awful_spawn.lua,v 1.1.2.2 2026/10/10 14:18:43 maya Exp $

lib, tests: use GioUnix to use platform-specific Gio classes (#4022)
* lib, tests: use GioUnix to use platform-specific Gio classes

In newest glib GioUnix symbols are not anymore exposed in GioUnix,
while lua-lgi should handle the change transparently, it's better to
adapt awesome to just use the right namespace.

https://github.com/awesomeWM/awesome/commit/179e2b483800dd37bec8663f053313a8e614db13

--- lib/awful/spawn.lua.orig	2019-01-28 06:53:24.000000000 +0000
+++ lib/awful/spawn.lua
@@ -225,6 +225,7 @@ local Gio = lgi.Gio
 }
 local lgi = require("lgi")
 local Gio = lgi.Gio
+local GioUnix = lgi.GioUnix
 local GLib = lgi.GLib
 local util   = require("awful.util")
 local gtable = require("gears.table")
@@ -411,11 +412,11 @@ function spawn.with_line_callback(cmd, callbacks)
         end
     end
     if have_stdout then
-        spawn.read_lines(Gio.UnixInputStream.new(stdout, true),
+        spawn.read_lines(GioUnix.InputStream.new(stdout, true),
                 stdout_callback, step_done, true)
     end
     if have_stderr then
-        spawn.read_lines(Gio.UnixInputStream.new(stderr, true),
+        spawn.read_lines(GioUnix.InputStream.new(stderr, true),
                 stderr_callback, step_done, true)
     end
     assert(stdin == nil)
