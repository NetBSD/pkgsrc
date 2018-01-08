$NetBSD: patch-servo_components_script_dom_websocket.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/websocket.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/websocket.rs
@@ -32,7 +32,6 @@ use net_traits::MessageData;
 use script_runtime::CommonScriptMsg;
 use script_runtime::ScriptThreadEventCategory::WebSocketEvent;
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::borrow::ToOwned;
 use std::cell::Cell;
 use std::ptr;
