# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:49 jlam Exp $

.if !defined(FOX_BUILDLINK2_MK)
FOX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		fox
BUILDLINK_DEPENDS.fox?=		fox>=0.99.174nb1
BUILDLINK_PKGSRCDIR.fox?=	../../x11/fox

EVAL_PREFIX+=		BUILDLINK_PREFIX.fox=fox
BUILDLINK_PREFIX.fox_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.fox=	include/fox/*
BUILDLINK_FILES.fox+=	lib/libFOX-*
BUILDLINK_FILES.fox+=	lib/libFOX.*

CPPFLAGS+=	-I${BUILDLINK_PREFIX.fox}/include/fox

BUILDLINK_TARGETS+=	fox-buildlink

fox-buildlink: _BUILDLINK_USE

.endif	# FOX_BUILDLINK2_MK
