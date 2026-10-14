$NetBSD: patch-crates_zensical-watch_src_agent_monitor.rs,v 1.1 2026/10/14 20:14:25 wiz Exp $

https://github.com/zensical/zensical/issues/1035

--- crates/zensical-watch/src/agent/monitor.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ crates/zensical-watch/src/agent/monitor.rs
@@ -26,9 +26,10 @@ use crossbeam::channel::{unbounded, Receiver, TryIter}
 //! File monitor.
 
 use crossbeam::channel::{unbounded, Receiver, TryIter};
+use notify::event::ModifyKind;
 use notify::{
-    Config, Event, PollWatcher, RecommendedWatcher, RecursiveMode, Result,
-    Watcher, WatcherKind,
+    Config, Event, EventKind, PollWatcher, RecommendedWatcher, RecursiveMode,
+    Result, Watcher, WatcherKind,
 };
 use std::collections::btree_map::Entry;
 use std::collections::BTreeMap;
@@ -573,6 +574,15 @@ where
 where
     W: 'static + Watcher,
 {
+    // IN_ATTRIB is emitted for metadata changes, including hardlink counts
+    // changed by package installations. These events, including timestamp-only
+    // changes, are ignored; content writes and renames are reported separately.
+    if W::kind() == Kind::Inotify
+        && matches!(event.kind, EventKind::Modify(ModifyKind::Metadata(_)))
+    {
+        return None;
+    }
+
     // Unfortunately, the `kqueue` file watcher backend spuriously emits paths
     // that were not actually touched if changes are detected inside symbolic
     // links, which is why we must check for them and ignore them. Only perform
@@ -595,4 +605,68 @@ where
         true
     }
     .then_some(event)
+}
+
+// ----------------------------------------------------------------------------
+// Tests
+// ----------------------------------------------------------------------------
+
+#[cfg(test)]
+mod tests {
+    use notify::event::MetadataKind;
+
+    use super::{filter, Event, EventKind, ModifyKind, PollWatcher};
+
+    #[cfg(target_os = "linux")]
+    #[test]
+    fn inotify_metadata_events_are_ignored() {
+        use notify::INotifyWatcher;
+
+        // Link counts and timestamps are included in inotify's metadata events.
+        for metadata in [
+            MetadataKind::Any,
+            MetadataKind::AccessTime,
+            MetadataKind::WriteTime,
+            MetadataKind::Permissions,
+            MetadataKind::Ownership,
+            MetadataKind::Extended,
+            MetadataKind::Other,
+        ] {
+            let event =
+                Event::new(EventKind::Modify(ModifyKind::Metadata(metadata)))
+                    .add_path("template.html".into());
+
+            assert!(filter::<INotifyWatcher>(event).is_none());
+        }
+    }
+
+    #[cfg(target_os = "linux")]
+    #[test]
+    fn inotify_content_and_path_changes_are_preserved() {
+        use notify::event::{CreateKind, DataChange, RemoveKind, RenameMode};
+        use notify::INotifyWatcher;
+
+        // Content writes and path changes must still reach the file manager.
+        for kind in [
+            EventKind::Create(CreateKind::File),
+            EventKind::Modify(ModifyKind::Data(DataChange::Content)),
+            EventKind::Modify(ModifyKind::Name(RenameMode::Both)),
+            EventKind::Remove(RemoveKind::File),
+        ] {
+            let event = Event::new(kind).add_path("template.html".into());
+
+            assert_eq!(filter::<INotifyWatcher>(event.clone()), Some(event));
+        }
+    }
+
+    #[test]
+    fn polling_metadata_events_are_preserved() {
+        // Metadata events from other backends are passed through unchanged.
+        let event = Event::new(EventKind::Modify(ModifyKind::Metadata(
+            MetadataKind::WriteTime,
+        )))
+        .add_path("template.html".into());
+
+        assert_eq!(filter::<PollWatcher>(event.clone()), Some(event));
+    }
 }
