$NetBSD: patch-servo_components_script_dom_htmlscriptelement.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/htmlscriptelement.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/htmlscriptelement.rs
@@ -36,7 +36,6 @@ use network_listener::{NetworkListener, 
 use servo_atoms::Atom;
 use servo_config::opts;
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::cell::Cell;
 use std::fs::File;
 use std::io::{Read, Write};
