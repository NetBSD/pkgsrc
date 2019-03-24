$NetBSD: patch-vendor_github.com_edsrzf_mmap-go_mmap.go,v 1.1 2019/03/24 21:34:23 nia Exp $

--- vendor/github.com/edsrzf/mmap-go/mmap.go.orig	2018-08-10 17:16:53.000000000 +0000
+++ vendor/github.com/edsrzf/mmap-go/mmap.go
@@ -80,37 +80,3 @@ func MapRegion(f *os.File, length int, p
 func (m *MMap) header() *reflect.SliceHeader {
 	return (*reflect.SliceHeader)(unsafe.Pointer(m))
 }
-
-// Lock keeps the mapped region in physical memory, ensuring that it will not be
-// swapped out.
-func (m MMap) Lock() error {
-	dh := m.header()
-	return lock(dh.Data, uintptr(dh.Len))
-}
-
-// Unlock reverses the effect of Lock, allowing the mapped region to potentially
-// be swapped out.
-// If m is already unlocked, aan error will result.
-func (m MMap) Unlock() error {
-	dh := m.header()
-	return unlock(dh.Data, uintptr(dh.Len))
-}
-
-// Flush synchronizes the mapping's contents to the file's contents on disk.
-func (m MMap) Flush() error {
-	dh := m.header()
-	return flush(dh.Data, uintptr(dh.Len))
-}
-
-// Unmap deletes the memory mapped region, flushes any remaining changes, and sets
-// m to nil.
-// Trying to read or write any remaining references to m after Unmap is called will
-// result in undefined behavior.
-// Unmap should only be called on the slice value that was originally returned from
-// a call to Map. Calling Unmap on a derived slice may cause errors.
-func (m *MMap) Unmap() error {
-	dh := m.header()
-	err := unmap(dh.Data, uintptr(dh.Len))
-	*m = nil
-	return err
-}
