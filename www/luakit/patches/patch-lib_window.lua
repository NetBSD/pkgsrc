$NetBSD: patch-lib_window.lua,v 1.1 2020/08/09 17:25:37 nia Exp $

Do not destroy() the current view.

When just one tab is present it leads to an high CPU usage and luakit completely
stuck (although start luakit via `--log=DEBUG' option shows that it responds to
events). To workaround this problem avoid to call view:destroy().

XXX: I'm not sure if it's the correct fix.

Reported uptsream via:

 <https://github.com/luakit/luakit/pull/726>

--- lib/window.lua.orig	2017-08-10 09:50:15.000000000 +0000
+++ lib/window.lua
@@ -519,7 +519,6 @@ window.methods = {
         view = view or w.view
         w:emit_signal("close-tab", view)
         w:detach_tab(view, blank_last)
-        view:destroy()
     end,
 
     attach_tab = function (w, view, switch, order)
