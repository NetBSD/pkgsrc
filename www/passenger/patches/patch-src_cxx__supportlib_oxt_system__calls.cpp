$NetBSD: patch-src_cxx__supportlib_oxt_system__calls.cpp,v 1.1 2020/03/27 20:51:23 joerg Exp $

--- src/cxx_supportlib/oxt/system_calls.cpp.orig	2020-03-27 15:09:11.254324657 +0000
+++ src/cxx_supportlib/oxt/system_calls.cpp
@@ -132,15 +132,15 @@ shouldSimulateFailure() {
 			_my_errno = errno; \
 		} while ((error_expression) \
 			&& _my_errno == EINTR \
-			&& (!this_thread::syscalls_interruptable() \
-			    || !(_intr_requested = this_thread::interruption_requested())) \
+			&& (!boost::this_thread::syscalls_interruptable() \
+			    || !(_intr_requested = boost::this_thread::interruption_requested())) \
 		); \
 		if (OXT_LIKELY(ctx != NULL)) { \
 			ctx->syscall_interruption_lock.lock(); \
 		} \
 		if ((error_expression) \
 		 && _my_errno == EINTR \
-		 && this_thread::syscalls_interruptable() \
+		 && boost::this_thread::syscalls_interruptable() \
 		 && _intr_requested) { \
 			throw thread_interrupted(); \
 		} \
@@ -284,8 +284,8 @@ syscalls::close(int fd) {
 		}
 		if (ret == -1
 		 && errno == EINTR
-		 && this_thread::syscalls_interruptable()
-		 && this_thread::interruption_requested()) {
+		 && boost::this_thread::syscalls_interruptable()
+		 && boost::this_thread::interruption_requested()) {
 			throw thread_interrupted();
 		} else {
 			return ret;
@@ -662,8 +662,8 @@ syscalls::nanosleep(const struct timespe
 		}
 	} while (ret == -1
 		&& e == EINTR
-		&& (!this_thread::syscalls_interruptable()
-		    || !(intr_requested = this_thread::interruption_requested()))
+		&& (!boost::this_thread::syscalls_interruptable()
+		    || !(intr_requested = boost::this_thread::interruption_requested()))
 	);
 
 	if (OXT_UNLIKELY(ctx != NULL)) {
@@ -672,7 +672,7 @@ syscalls::nanosleep(const struct timespe
 
 	if (ret == -1
 	 && e == EINTR
-	 && this_thread::syscalls_interruptable()
+	 && boost::this_thread::syscalls_interruptable()
 	 && intr_requested) {
 		throw thread_interrupted();
 	}
@@ -748,14 +748,14 @@ syscalls::waitpid(pid_t pid, int *status
 	 * http://stackoverflow.com/questions/20410943/segmentation-fault-when-accessing-statically-initialized-thread-variable?noredirect=1#comment30483943_20410943
 	 * https://bugzilla.redhat.com/show_bug.cgi?id=731228
 	 */
-	__thread int this_thread::_syscalls_interruptable = 1;
+	__thread int boost::this_thread::_syscalls_interruptable = 1;
 
 	bool
 	boost::this_thread::syscalls_interruptable() {
 		return _syscalls_interruptable;
 	}
 #else
-	boost::thread_specific_ptr<bool> this_thread::_syscalls_interruptable;
+	boost::thread_specific_ptr<bool> boost::this_thread::_syscalls_interruptable;
 
 	bool
 	boost::this_thread::syscalls_interruptable() {
