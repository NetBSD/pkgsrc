# $NetBSD: buildlink2.mk,v 1.2 2002/09/23 08:29:59 jlam Exp $

.if !defined(NEXTAW_BUILDLINK2_MK)
NEXTAW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		neXtaw
BUILDLINK_DEPENDS.neXtaw?=	neXtaw>=0.12
BUILDLINK_PKGSRCDIR.neXtaw?=	../../x11/neXtaw

EVAL_PREFIX+=	BUILDLINK_PREFIX.neXtaw=neXtaw
BUILDLINK_PREFIX.neXtaw_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.neXtaw+=		include/X11/neXtaw/*
BUILDLINK_FILES.neXtaw+=		lib/libneXtaw.*

BUILDLINK_TARGETS+=	neXtaw-buildlink

LIBXAW?=	-L${BUILDLINK_PREFIX.neXtaw}/lib			\
		-Wl,-R${BUILDLINK_PREFIX.neXtaw}/lib			\
		-lneXtaw

neXtaw-buildlink: _BUILDLINK_USE

.endif	# NEXTAW_BUILDLINK2_MK
