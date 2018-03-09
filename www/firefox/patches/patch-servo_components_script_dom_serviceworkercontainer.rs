$NetBSD: patch-servo_components_script_dom_serviceworkercontainer.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/serviceworkercontainer.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/serviceworkercontainer.rs
@@ -16,7 +16,6 @@ use dom::serviceworker::ServiceWorker;
 use dom_struct::dom_struct;
 use script_thread::ScriptThread;
 use serviceworkerjob::{Job, JobType};
-use std::ascii::AsciiExt;
 use std::default::Default;
 use std::rc::Rc;
 
