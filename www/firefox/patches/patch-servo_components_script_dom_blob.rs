$NetBSD: patch-servo_components_script_dom_blob.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/blob.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/blob.rs
@@ -16,7 +16,6 @@ use ipc_channel::ipc;
 use net_traits::{CoreResourceMsg, IpcSend};
 use net_traits::blob_url_store::{BlobBuf, get_blob_origin};
 use net_traits::filemanager_thread::{FileManagerThreadMsg, ReadFileProgress, RelativePos};
-use std::ascii::AsciiExt;
 use std::mem;
 use std::ops::Index;
 use std::path::PathBuf;
