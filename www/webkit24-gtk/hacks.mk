# $NetBSD: hacks.mk,v 1.1.34.1 2020/09/18 18:22:25 bsiegert Exp $

.if !defined(WEBKIT24_GTK_HACKS_MK)
WEBKIT24_GTK_HACKS_MK=	defined

# [Sun Mar 20 12:21:27 CET 2016 : leot]
# On i386 archs -latomic is added during the build phase and lead to a failure
# when linking various binaries/libraries.
# Forcing -march=i586 (or better) avoids that (i[56]86 provide required
# 64-bit compare-and-swap instruction).
.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomicops
CXXFLAGS+=	-march=i586
.endif

# [Fri Sep 11 11:23:52 CEST 2020 : he]
# On NetBSD/powerpc, we don't have native 8-byte atomics,
# but webkit24-gtk insists on using them, so here we need libatomic.
# (This is a trial balloon -- let's see if autoconf will pick it up...)
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=	powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# WEBKIT24_GTK_HACKS_MK
