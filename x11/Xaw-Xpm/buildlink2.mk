# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:26 jlam Exp $

.if !defined(XAWXPM_BUILDLINK2_MK)
XAWXPM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		Xaw-Xpm
BUILDLINK_DEPENDS.Xaw-Xpm?=	Xaw-Xpm-1.1
BUILDLINK_PKGSRCDIR.Xaw-Xpm?=	../../x11/Xaw-Xpm

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
