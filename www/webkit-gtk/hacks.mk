# $NetBSD: hacks.mk,v 1.1.2.2 2015/10/08 00:12:56 spz Exp $

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

.endif	# WEBKIT_GTK_HACKS_MK

