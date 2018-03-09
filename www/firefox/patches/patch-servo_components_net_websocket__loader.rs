$NetBSD: patch-servo_components_net_websocket__loader.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/net/websocket_loader.rs.orig	2017-11-02 16:16:32.000000000 +0000
+++ servo/components/net/websocket_loader.rs
@@ -19,7 +19,6 @@ use net_traits::{CookieSource, MessageDa
 use net_traits::{WebSocketDomAction, WebSocketNetworkEvent};
 use net_traits::request::{Destination, Type};
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::io::{self, Write};
 use std::net::TcpStream;
 use std::sync::{Arc, Mutex};
