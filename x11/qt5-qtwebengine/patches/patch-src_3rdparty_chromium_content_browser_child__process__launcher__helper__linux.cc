$NetBSD: patch-src_3rdparty_chromium_content_browser_child__process__launcher__helper__linux.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/child_process_launcher_helper_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/child_process_launcher_helper_linux.cc
@@ -19,7 +19,9 @@
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !defined(OS_BSD)
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/policy/linux/sandbox_linux.h"
 
 namespace content {
@@ -50,10 +52,12 @@ bool ChildProcessLauncherHelper::BeforeL
   options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
       base::GlobalDescriptors::kBaseDescriptor);
 
+#if !defined(OS_BSD)
   if (GetProcessType() == switches::kRendererProcess) {
     const int sandbox_fd = SandboxHostLinux::GetInstance()->GetChildSocket();
     options->fds_to_remap.push_back(std::make_pair(sandbox_fd, GetSandboxFD()));
   }
+#endif
 
   options->environment = delegate_->GetEnvironment();
 
@@ -68,6 +72,7 @@ ChildProcessLauncherHelper::LaunchProces
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -81,7 +86,6 @@ ChildProcessLauncherHelper::LaunchProces
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !defined(OS_OPENBSD)
     if (handle) {
       // It could be a renderer process or an utility process.
       int oom_score = content::kMiscOomScore;
@@ -90,13 +94,13 @@ ChildProcessLauncherHelper::LaunchProces
         oom_score = content::kLowestRendererOomScore;
       ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(handle, oom_score);
     }
-#endif
 
     Process process;
     process.process = base::Process(handle);
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -114,10 +118,13 @@ ChildProcessTerminationInfo ChildProcess
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !defined(OS_BSD)
   if (process.zygote) {
     info.status = process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, &info.exit_code);
-  } else if (known_dead) {
+  } else
+#endif
+  if (known_dead) {
     info.status = base::GetKnownDeadTerminationStatus(process.process.Handle(),
                                                       &info.exit_code);
   } else {
@@ -141,13 +148,17 @@ void ChildProcessLauncherHelper::ForceNo
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !defined(OS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !defined(OS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
