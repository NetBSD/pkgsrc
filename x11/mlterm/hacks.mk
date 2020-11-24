# $NetBSD: hacks.mk,v 1.2 2020/11/24 09:29:45 tsutsui Exp $

.if !defined(MLTERM_HACKS_MK)
MLTERM_HACKS_MK=	defined

.include "../../mk/compiler.mk"

# On NetBSD/sh3el 9.0 (gcc 7.4.0) and 9.1 (gcc 7.5.0), the default -Os
# causes an error on compiling vt_line_bidi.c and -fno-dce works around.
# (PR/55265)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sh3*) && !empty(CC_VERSION:Mgcc-7.*)
PKG_HACKS+=		optimisation
# XXX: is there any good way to replace the default -Os with multiple args?
#BUILDLINK_TRANSFORM+=
CFLAGS+=		-fno-dce
.endif

.endif	# MLTERM_HACKS_MK
