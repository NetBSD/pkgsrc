$NetBSD: patch-crates_zensical_src_watcher.rs,v 1.1 2026/10/14 20:14:25 wiz Exp $

https://github.com/zensical/zensical/issues/1035

--- crates/zensical/src/watcher.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ crates/zensical/src/watcher.rs
@@ -237,30 +237,17 @@ impl Watcher {
                     {
                         continue;
                     }
-                    // Check if the config file reloaded, and terminate agent,
-                    // as we need to kick off the entire pipeline again
-                    if event_path == config_path && !seen.insert(event.path()) {
+                    if should_restart(
+                        &event,
+                        &event_path,
+                        &config_path,
+                        &theme_dirs,
+                        &watched_files,
+                        &mut seen,
+                    ) {
                         return Err(Error::Disconnected);
                     }
 
-                    // Check if the event is in any of the theme directories
-                    // and restart the build if we've already seen the file
-                    for dir in &theme_dirs {
-                        if event_path.starts_with(dir)
-                            && !seen.insert(event.path())
-                        {
-                            return Err(Error::Disconnected);
-                        }
-                    }
-
-                    // Check if one of the source files managed by mkdocstrings
-                    // changed, and restart the build
-                    if watched_files.contains(&event_path)
-                        && !seen.insert(event.path())
-                    {
-                        return Err(Error::Disconnected);
-                    }
-
                     // Ignore events in the site directory, since they are files
                     // that were generated and should not trigger a rebuild. We
                     // forward them to the reload channel in the server instead,
@@ -475,16 +462,161 @@ fn canonical_or_clone(path: &Path) -> PathBuf {
     fs::canonicalize(path).unwrap_or_else(|_| path.to_path_buf())
 }
 
+/// A restart is requested when a previously discovered input is seen again.
+fn should_restart(
+    event: &Event, event_path: &Path, config_path: &Path,
+    theme_dirs: &[PathBuf], watched_files: &BTreeSet<PathBuf>,
+    seen: &mut BTreeSet<Arc<PathBuf>>,
+) -> bool {
+    // Discovery is recorded once per event because restart categories can overlap.
+    let watched = event_path == config_path
+        || theme_dirs.iter().any(|dir| event_path.starts_with(dir))
+        || watched_files.contains(event_path);
+    watched && !seen.insert(event.path())
+}
+
 // ----------------------------------------------------------------------------
 // Tests
 // ----------------------------------------------------------------------------
 
 #[cfg(test)]
 mod tests {
+    use std::collections::BTreeSet;
+    use std::path::PathBuf;
+    use std::sync::Arc;
     use std::{fs, io};
     use tempfile::tempdir;
 
-    use super::{to_id, Manager, SourceMount};
+    use super::{should_restart, to_id, Event, Kind, Manager, SourceMount};
+
+    #[test]
+    fn restart_inputs_are_discovered_once_and_restarted_after_edits() {
+        let config = PathBuf::from("project/zensical.toml");
+        let theme = PathBuf::from("project/docs/.overrides");
+        let icon = theme.join(".icons/custom.svg");
+        let template = theme.join("main.html");
+        let include = PathBuf::from("project/docs/fragment.j2");
+
+        // Inputs are covered by individual and overlapping restart categories.
+        let cases = [
+            (config.clone(), vec![], BTreeSet::new()),
+            (template, vec![theme.clone()], BTreeSet::new()),
+            (include.clone(), vec![], BTreeSet::from([include])),
+            (config.clone(), vec![], BTreeSet::from([config.clone()])),
+            (
+                icon.clone(),
+                vec![theme.clone()],
+                BTreeSet::from([icon.clone()]),
+            ),
+            (
+                icon.clone(),
+                vec![theme.clone(), theme.join(".icons")],
+                BTreeSet::new(),
+            ),
+        ];
+
+        for (path, theme_dirs, watched_files) in cases {
+            let mut seen = BTreeSet::new();
+            let discovery = Event::Create {
+                kind: Kind::File,
+                path: Arc::new(path.clone()),
+            };
+
+            // Initial discovery must be admitted even if categories overlap.
+            assert!(
+                !should_restart(
+                    &discovery,
+                    &path,
+                    &config,
+                    &theme_dirs,
+                    &watched_files,
+                    &mut seen,
+                ),
+                "initial discovery of {path:?}"
+            );
+
+            let edit = Event::Modify {
+                kind: Kind::File,
+                path: Arc::new(path.clone()),
+            };
+
+            // A restart must still be requested by a subsequent edit.
+            assert!(
+                should_restart(
+                    &edit,
+                    &path,
+                    &config,
+                    &theme_dirs,
+                    &watched_files,
+                    &mut seen,
+                ),
+                "edit to {path:?}"
+            );
+        }
+    }
+
+    #[test]
+    fn ordinary_document_edits_do_not_restart_the_build() {
+        let path = PathBuf::from("project/docs/index.md");
+        let event = Event::Modify {
+            kind: Kind::File,
+            path: Arc::new(path.clone()),
+        };
+        let config = PathBuf::from("project/zensical.toml");
+        let mut seen = BTreeSet::new();
+
+        // Ordinary document events are admitted to the existing workflow.
+        for _ in 0..2 {
+            assert!(!should_restart(
+                &event,
+                &path,
+                &config,
+                &[],
+                &BTreeSet::new(),
+                &mut seen,
+            ));
+        }
+    }
+
+    #[test]
+    fn watched_symlink_aliases_are_discovered_independently() {
+        let config = PathBuf::from("project/zensical.toml");
+        let target = PathBuf::from("project/fragment.j2");
+        let watched_files = BTreeSet::from([target.clone()]);
+        let mut seen = BTreeSet::new();
+
+        // Aliases are resolved to the same watched target during discovery.
+        for path in ["project/docs/first.j2", "project/docs/second.j2"] {
+            let discovery = Event::Create {
+                kind: Kind::Link,
+                path: Arc::new(PathBuf::from(path)),
+            };
+
+            assert!(!should_restart(
+                &discovery,
+                &target,
+                &config,
+                &[],
+                &watched_files,
+                &mut seen,
+            ));
+        }
+
+        let edit = Event::Modify {
+            kind: Kind::Link,
+            path: Arc::new(PathBuf::from("project/docs/first.j2")),
+        };
+
+        // A restart must be requested when an existing alias is seen again.
+        assert!(should_restart(
+            &edit,
+            &target,
+            &config,
+            &[],
+            &watched_files,
+            &mut seen,
+        ));
+    }
 
     #[test]
     fn hidden_directory_discovery_is_limited_to_documentation() {
