# $NetBSD: buildlink.mk,v 1.1 2002/07/17 12:51:29 agc Exp $
#
# This Makefile fragment is included by packages that use gtkglarea.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtkglarea to the dependency pattern
#     for the version of gtkglarea desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTKGLAREA_BUILDLINK_MK)
GTKGLAREA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtkglarea?=		gtkglarea>=1.2.2
DEPENDS+=	${BUILDLINK_DEPENDS.gtkglarea}:../../x11/gtkglarea

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkglarea=gtkglarea
BUILDLINK_PREFIX.gtkglarea_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkglarea+=	include/gtkgl/gdkgl.h
BUILDLINK_FILES.gtkglarea+=	include/gtkgl/gtkglarea.h
BUILDLINK_FILES.gtkglarea+=	lib/libgtkgl.*


BUILDLINK_TARGETS.gtkglarea=	gtkglarea-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gtkglarea}

pre-configure: ${BUILDLINK_TARGETS}
gtkglarea-buildlink: _BUILDLINK_USE

.endif	# GTKGLAREA_BUILDLINK_MK
