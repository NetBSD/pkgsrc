# $NetBSD: hacks.mk,v 1.2 2020/09/11 09:21:32 he Exp $

.if !defined(WEBKIT_GTK_HACKS_MK)
WEBKIT_GTK_HACKS_MK=	defined

# [Sat Oct  3 16:44:53 CEST 2015 : leot]
# On i386 archs -latomic is added during the build phase when linking
# libwebkit2gtk-4.0.so for atomic operations.
# Forcing -march=i586 (or better) avoids that (i[56]86 provide required
# 64-bit compare-and-swap instruction).
.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomicops
CXXFLAGS+=	-march=i586
.endif

# [Mon Sep  7 20:40:36 CEST 2020 : he]
# On NetBSD/powerpc, we don't have native 8-byte atomics,
# but webkit-gtk insists on using them, so here we need libatomic.
# (This is a trial balloon -- let's see if autoconf will pick it up...)
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=     powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# WEBKIT_GTK_HACKS_MK
