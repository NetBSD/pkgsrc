# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:53 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw-Xpm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Xaw-Xpm to the dependency pattern
#     for the version of Xaw-Xpm desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(XAWXPM_BUILDLINK2_MK)
XAWXPM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.Xaw-Xpm?=	Xaw-Xpm-1.1
DEPENDS+=	${BUILDLINK_DEPENDS.Xaw-Xpm}:../../x11/Xaw-Xpm

EVAL_PREFIX+=	BUILDLINK_PREFIX.Xaw-Xpm=Xaw-Xpm
BUILDLINK_PREFIX.Xaw-Xpm_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.Xaw-Xpm=	include/X11/Xaw3d/*
BUILDLINK_FILES.Xaw-Xpm+=	lib/libXaw3d.*

.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	Xaw-Xpm-buildlink

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw-Xpm}/lib			\
		-L${BUILDLINK_PREFIX.xpm}/lib -lXaw3d -lXpm

Xaw-Xpm-buildlink: _BUILDLINK_USE

.endif	# XAWXPM_BUILDLINK2_MK
