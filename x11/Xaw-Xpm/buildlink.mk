# $NetBSD: buildlink.mk,v 1.1 2001/08/23 04:24:22 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw-Xpm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Xaw-Xpm to the dependency pattern
#     for the version of Xaw-Xpm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XAWXPM_BUILDLINK_MK)
XAWXPM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.Xaw-Xpm?=	Xaw-Xpm-1.1
DEPENDS+=	${BUILDLINK_DEPENDS.Xaw-Xpm}:../../x11/Xaw-Xpm

EVAL_PREFIX+=			BUILDLINK_PREFIX.Xaw-Xpm=Xaw-Xpm
BUILDLINK_PREFIX.Xaw-Xpm_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.Xaw-Xpm=	include/X11/Xaw3d/*
BUILDLINK_FILES.Xaw-Xpm+=	lib/libXaw3d.*

.include "../../graphics/xpm/buildlink.mk"

BUILDLINK_TARGETS.Xaw-Xpm+=	Xaw-Xpm-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.Xaw-Xpm}

LIBXAW?=	-L${BUILDLINK_DIR}/lib -L${BUILDLINK_X11_DIR}/lib -lXaw3d -lXpm
MAKE_ENV+=	LIBXAW="${LIBXAW}"

pre-configure: ${BUILDLINK_TARGETS.Xaw-Xpm}
Xaw-Xpm-buildlink: _BUILDLINK_USE

.endif	# XAWXPM_BUILDLINK_MK
