# $NetBSD: buildlink2.mk,v 1.3 2002/09/23 02:28:39 jlam Exp $

.if !defined(WX1MOTIF_BUILDLINK2_MK)
WX1MOTIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wx1Motif
BUILDLINK_DEPENDS.wx1Motif?=	wx1Motif>=1.68e
BUILDLINK_PKGSRCDIR.wx1Motif?=	../../x11/wx1Motif

EVAL_PREFIX+=				BUILDLINK_PREFIX.wx1Motif=wx1Motif
BUILDLINK_PREFIX.wx1Motif_DEFAULT=	${X11PREFIX}

BUILDLINK_FILES.wx1Motif=	include/wxwindows1/*
BUILDLINK_FILES.wx1Motif+=	lib/wxwindows1/libwx_motif.a

BUILDLINK_CPPFLAGS.wx1Motif= \
	-I${BUILDLINK_PREFIX.wx1Motif}/include/wxwindows1
BUILDLINK_LDFLAGS.wx1Motif= \
	-L${BUILDLINK_PREFIX.wx1Motif}/lib/wxwindows1

CFLAGS+=		${BUILDLINK_CPPFLAGS.wx1Motif}
CXXFLAGS+=		${BUILDLINK_CPPFLAGS.wx1Motif}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.wx1Motif}
LDFLAGS+=		${BUILDLINK_LDFLAGS.wx1Motif}

.include "../../mk/motif.buildlink2.mk"

BUILDLINK_TARGETS+=	wx1Motif-buildlink

wx1Motif-buildlink: _BUILDLINK_USE

.endif	# WX1MOTIF_BUILDLINK2_MK
