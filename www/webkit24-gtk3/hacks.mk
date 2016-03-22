# $NetBSD: hacks.mk,v 1.1 2016/03/22 20:10:15 leot Exp $

.if !defined(WEBKIT24_GTK3_HACKS_MK)
WEBKIT24_GTK3_HACKS_MK=	defined

# [Sun Mar 20 12:21:27 CET 2016 : leot]
# On i386 archs -latomic is added during the build phase and lead to a failure
# when linking various binaries/libraries.
# Forcing -march=i586 (or better) avoids that (i[56]86 provide required
# 64-bit compare-and-swap instruction).
.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomicops
CXXFLAGS+=	-march=i586
.endif

.endif	# WEBKIT24_GTK3_HACKS_MK
