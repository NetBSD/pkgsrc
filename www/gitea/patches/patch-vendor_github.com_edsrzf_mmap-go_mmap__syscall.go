$NetBSD: patch-vendor_github.com_edsrzf_mmap-go_mmap__syscall.go,v 1.1 2019/03/24 21:34:23 nia Exp $

--- vendor/github.com/edsrzf/mmap-go/mmap_syscall.go.orig	2018-08-27 13:51:58.192608409 +0000
+++ vendor/github.com/edsrzf/mmap-go/mmap_syscall.go
@@ -0,0 +1,41 @@
+// Copyright 2011 Evan Shaw. All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+// +build !solaris
+
+package mmap
+
+// Lock keeps the mapped region in physical memory, ensuring that it will not be
+// swapped out.
+func (m MMap) Lock() error {
+	dh := m.header()
+	return lock(dh.Data, uintptr(dh.Len))
+}
+
+// Unlock reverses the effect of Lock, allowing the mapped region to potentially
+// be swapped out.
+// If m is already unlocked, aan error will result.
+func (m MMap) Unlock() error {
+	dh := m.header()
+	return unlock(dh.Data, uintptr(dh.Len))
+}
+
+// Flush synchronizes the mapping's contents to the file's contents on disk.
+func (m MMap) Flush() error {
+	dh := m.header()
+	return flush(dh.Data, uintptr(dh.Len))
+}
+
+// Unmap deletes the memory mapped region, flushes any remaining changes, and sets
+// m to nil.
+// Trying to read or write any remaining references to m after Unmap is called will
+// result in undefined behavior.
+// Unmap should only be called on the slice value that was originally returned from
+// a call to Map. Calling Unmap on a derived slice may cause errors.
+func (m *MMap) Unmap() error {
+	dh := m.header()
+	err := unmap(dh.Data, uintptr(dh.Len))
+	*m = nil
+	return err
+}
