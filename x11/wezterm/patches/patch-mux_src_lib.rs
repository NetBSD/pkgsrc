$NetBSD: patch-mux_src_lib.rs,v 1.1 2025/02/22 14:41:44 wiz Exp $

NetBSD by default doesn't support buffer sizes above 256kB.
https://github.com/wezterm/wezterm/issues/6712

--- mux/src/lib.rs.orig	2025-02-22 14:29:36.911953440 +0000
+++ mux/src/lib.rs
@@ -115,7 +115,7 @@ pub struct Mux {
     agent: Option<AgentProxy>,
 }
 
-const BUFSIZE: usize = 1024 * 1024;
+const BUFSIZE: usize = 128 * 1024;
 
 /// This function applies parsed actions to the pane and notifies any
 /// mux subscribers about the output event
