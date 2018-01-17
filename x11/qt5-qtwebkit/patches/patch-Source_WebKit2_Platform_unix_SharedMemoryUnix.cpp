$NetBSD: patch-Source_WebKit2_Platform_unix_SharedMemoryUnix.cpp,v 1.2 2018/01/17 19:37:33 markd Exp $

* Try to use /tmp/* file like shared memory, I am not sure.

--- Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp.orig	2017-06-04 20:16:07.000000000 +0000
+++ Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp
@@ -96,14 +96,25 @@ void SharedMemory::Handle::adoptAttachme
 RefPtr<SharedMemory> SharedMemory::allocate(size_t size)
 {
     CString tempName;
+    CString buf;
 
     int fileDescriptor = -1;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
         String name = String("/WK2SharedMemory.") + String::number(static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
         tempName = name.utf8();
+        String bbuf = String("/tmp") + name;
+        buf = bbuf.utf8();
 
         do {
+#if !defined(__NetBSD__)
             fileDescriptor = shm_open(tempName.data(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
+#else
+            fileDescriptor = open(buf.data(), O_CREAT | O_CLOEXEC | O_RDWR, S_IRUSR | S_IWUSR);
+            if (fileDescriptor == -1 && errno == EEXIST) {
+                unlink(buf.data());
+               fileDescriptor = open(buf.data(), O_CREAT | O_CLOEXEC | O_RDWR, S_IRUSR | S_IWUSR);
+            }
+#endif
         } while (fileDescriptor == -1 && errno == EINTR);
     }
     if (fileDescriptor == -1) {
@@ -114,7 +125,12 @@ RefPtr<SharedMemory> SharedMemory::alloc
     while (ftruncate(fileDescriptor, size) == -1) {
         if (errno != EINTR) {
             closeWithRetry(fileDescriptor);
+#if !defined(__NetBSD__)
             shm_unlink(tempName.data());
+#else
+            close(fileDescriptor);
+            unlink(buf.data());
+#endif
             return 0;
         }
     }
@@ -122,11 +138,21 @@ RefPtr<SharedMemory> SharedMemory::alloc
     void* data = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0);
     if (data == MAP_FAILED) {
         closeWithRetry(fileDescriptor);
+#if !defined(__NetBSD__)
         shm_unlink(tempName.data());
+#else
+    close(fileDescriptor);
+    unlink(buf.data());
+#endif
         return 0;
     }
 
+#if !defined(__NetBSD__)
     shm_unlink(tempName.data());
+#else
+    close(fileDescriptor);
+    unlink(buf.data());
+#endif
 
     RefPtr<SharedMemory> instance = adoptRef(new SharedMemory());
     instance->m_data = data;
