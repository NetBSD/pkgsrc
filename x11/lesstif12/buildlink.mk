# $NetBSD: buildlink.mk,v 1.7 2001/08/06 10:53:48 tron Exp $
#
# This Makefile fragment is included by packages that use lesstif12.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lesstif12 to the dependency pattern
#     for the version of lesstif12 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LESSTIF12_BUILDLINK_MK)
LESSTIF12_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lesstif12?=	lesstif12>=0.91.4

.include "../../mk/bsd.prefs.mk"

# On Solaris, assume that /usr/dt contains a valid Motif 1.2-compatible
# installation.  Otherwise, check to see if <Xm/Gadget.h> is installed.
# If it is, then this is a Motif 2.0-compatible installation, so we need
# lesstif12.
#
.if ${OPSYS} == "SunOS"
_NEED_LESSTIF12=	NO
.else
.if exists(${X11BASE}/include/Xm/Xm.h)
.if exists(${X11BASE}/include/Xm/Gadget.h)
_NEED_LESSTIF12=	YES
.else
_IS_LESSTIF!=		${EGREP} -c LESSTIF ${X11BASE}/include/Xm/Xm.h || ${TRUE}
.if ${_IS_LESSTIF} == "0"
_NEED_LESSTIF12=	NO
.else
_NEED_LESSTIF12=	YES
.endif
.endif
.else
_NEED_LESSTIF12=	YES
.endif
.endif

.if ${_NEED_LESSTIF12} == "YES"
MOTIFBASE?=	${X11PREFIX}/LessTif/Motif1.2
DEPENDS+=	${BUILDLINK_DEPENDS.lesstif12}:../../x11/lesstif12
.else
.if ${OPSYS} == "SunOS"
MOTIFBASE?=	/usr/dt
.else
MOTIFBASE?=	${X11BASE}
.endif
.endif

EVAL_PREFIX+=			LESSTIF12_PREFIX=lesstif12
BUILDLINK_PREFIX.lesstif12=	${LESSTIF12_PREFIX}/LessTif/Motif1.2
BUILDLINK_FILES.lesstif12=	include/Mrm/*
BUILDLINK_FILES.lesstif12+=	include/Xm/*
BUILDLINK_FILES.lesstif12+=	include/uil/*
BUILDLINK_FILES.lesstif12+=	lib/libMrm.*
BUILDLINK_FILES.lesstif12+=	lib/libUil.*
BUILDLINK_FILES.lesstif12+=	lib/libXm.*

BUILDLINK_TARGETS.lesstif12=	lesstif12-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.lesstif12}

USE_X11=	# defined
MAKE_ENV+=	MOTIFLIB="${MOTIFLIB}"
LDFLAGS+=	-Wl,-R${MOTIFBASE}/lib
MOTIFLIB?=	-Wl,-R${MOTIFBASE}/lib -Wl,-R${X11BASE}/lib -L${BUILDLINK_DIR}/lib -L${X11BASE}/lib -lXm -lXp

pre-configure: ${BUILDLINK_TARGETS.lesstif12}
lesstif12-buildlink: _BUILDLINK_USE

.endif	# LESSTIF12_BUILDLINK_MK
