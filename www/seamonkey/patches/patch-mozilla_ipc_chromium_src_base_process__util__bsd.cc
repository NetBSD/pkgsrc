$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util__bsd.cc,v 1.10 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util_bsd.cc.orig	2014-06-13 00:45:30.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util_bsd.cc
@@ -15,7 +15,9 @@
 
 #include <ctype.h>
 #include <fcntl.h>
+#if defined(OS_BSD)
 #include <kvm.h>
+#endif
 #include <unistd.h>
 
 #include <string>
@@ -311,6 +313,141 @@ void SetCurrentProcessPrivileges(ChildPr
 
 #endif
 
+#if defined(OS_MACOSX)
+NamedProcessIterator::NamedProcessIterator(const std::wstring& executable_name,
+                                           const ProcessFilter* filter)
+  : executable_name_(executable_name),
+    index_of_kinfo_proc_(0),
+    filter_(filter) {
+  // Get a snapshot of all of my processes (yes, as we loop it can go stale, but
+  // but trying to find where we were in a constantly changing list is basically
+  // impossible.
+
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_UID, int(geteuid()) };
+
+  // Since more processes could start between when we get the size and when
+  // we get the list, we do a loop to keep trying until we get it.
+  bool done = false;
+  int try_num = 1;
+  const int max_tries = 10;
+  do {
+    // Get the size of the buffer
+    size_t len = 0;
+    if (sysctl(mib, arraysize(mib), NULL, &len, NULL, 0) < 0) {
+      CHROMIUM_LOG(ERROR) << "failed to get the size needed for the process list";
+      kinfo_procs_.resize(0);
+      done = true;
+    } else {
+      size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+      // Leave some spare room for process table growth (more could show up
+      // between when we check and now)
+      num_of_kinfo_proc += 4;
+      kinfo_procs_.resize(num_of_kinfo_proc);
+      len = num_of_kinfo_proc * sizeof(struct kinfo_proc);
+      // Load the list of processes
+      if (sysctl(mib, arraysize(mib), &kinfo_procs_[0], &len, NULL, 0) < 0) {
+        // If we get a mem error, it just means we need a bigger buffer, so
+        // loop around again.  Anything else is a real error and give up.
+        if (errno != ENOMEM) {
+          CHROMIUM_LOG(ERROR) << "failed to get the process list";
+          kinfo_procs_.resize(0);
+          done = true;
+        }
+      } else {
+        // Got the list, just make sure we're sized exactly right
+        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+        kinfo_procs_.resize(num_of_kinfo_proc);
+        done = true;
+      }
+    }
+  } while (!done && (try_num++ < max_tries));
+
+  if (!done) {
+    CHROMIUM_LOG(ERROR) << "failed to collect the process list in a few tries";
+    kinfo_procs_.resize(0);
+  }
+}
+
+NamedProcessIterator::~NamedProcessIterator() {
+}
+
+const ProcessEntry* NamedProcessIterator::NextProcessEntry() {
+  bool result = false;
+  do {
+    result = CheckForNextProcess();
+  } while (result && !IncludeEntry());
+
+  if (result) {
+    return &entry_;
+  }
+
+  return NULL;
+}
+
+bool NamedProcessIterator::CheckForNextProcess() {
+  std::string executable_name_utf8(WideToUTF8(executable_name_));
+
+  std::string data;
+  std::string exec_name;
+
+  for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++index_of_kinfo_proc_) {
+    kinfo_proc* kinfo = &kinfo_procs_[index_of_kinfo_proc_];
+
+    // Skip processes just awaiting collection
+    if ((kinfo->kp_proc.p_pid > 0) && (kinfo->kp_proc.p_stat == SZOMB))
+      continue;
+
+    int mib[] = { CTL_KERN, KERN_PROCARGS, kinfo->kp_proc.p_pid };
+
+    // Found out what size buffer we need
+    size_t data_len = 0;
+    if (sysctl(mib, arraysize(mib), NULL, &data_len, NULL, 0) < 0) {
+      CHROMIUM_LOG(ERROR) << "failed to figure out the buffer size for a commandline";
+      continue;
+    }
+
+    data.resize(data_len);
+    if (sysctl(mib, arraysize(mib), &data[0], &data_len, NULL, 0) < 0) {
+      CHROMIUM_LOG(ERROR) << "failed to fetch a commandline";
+      continue;
+    }
+
+    // Data starts w/ the full path null termed, so we have to extract just the
+    // executable name from the path.
+
+    size_t exec_name_end = data.find('\0');
+    if (exec_name_end == std::string::npos) {
+      CHROMIUM_LOG(ERROR) << "command line data didn't match expected format";
+      continue;
+    }
+    size_t last_slash = data.rfind('/', exec_name_end);
+    if (last_slash == std::string::npos)
+      exec_name = data.substr(0, exec_name_end);
+    else
+      exec_name = data.substr(last_slash + 1, exec_name_end - last_slash - 1);
+
+    // Check the name
+    if (executable_name_utf8 == exec_name) {
+      entry_.pid = kinfo->kp_proc.p_pid;
+      entry_.ppid = kinfo->kp_eproc.e_ppid;
+      base::strlcpy(entry_.szExeFile, exec_name.c_str(),
+                    sizeof(entry_.szExeFile));
+      // Start w/ the next entry next time through
+      ++index_of_kinfo_proc_;
+      // Done
+      return true;
+    }
+  }
+  return false;
+}
+
+bool NamedProcessIterator::IncludeEntry() {
+  // Don't need to check the name, we did that w/in CheckForNextProcess.
+  if (!filter_)
+    return true;
+  return filter_->Includes(entry_.pid, entry_.ppid);
+}
+#else
 NamedProcessIterator::NamedProcessIterator(const std::wstring& executable_name,
                                            const ProcessFilter* filter)
 {
@@ -370,5 +507,6 @@ const ProcessEntry* NamedProcessIterator
   if (nextEntry >= content.size()) return NULL;
   return &content[nextEntry++];
 }
+#endif
 
 }  // namespace base
