# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:59 jlam Exp $

.if !defined(WX1MOTIF_BUILDLINK2_MK)
WX1MOTIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wx1Motif
BUILDLINK_DEPENDS.wx1Motif?=	wx1Motif>=1.68e
BUILDLINK_PKGSRCDIR.wx1Motif?=	../../x11/wx1Motif

EVAL_PREFIX+=				BUILDLINK_PREFIX.wx1Motif=wx1Motif
BUILDLINK_PREFIX.wx1Motif_DEFAULT=	${X11PREFIX}

BUILDLINK_FILES.wx1Motif=	include/wxwindows1/*
BUILDLINK_FILES.wx1Motif+=	lib/wxwindows1/libwx_motif.a

WX1MOTIF_CPPFLAGS=        -I${BUILDLINK_PREFIX.wx1Motif}/include/wxwindows1
WX1MOTIF_LDFLAGS=         -L${BUILDLINK_PREFIX.wx1Motif}/lib/wxwindows1

CFLAGS+=                ${WX1MOTIF_CPPFLAGS}
CXXFLAGS+=              ${WX1MOTIF_CPPFLAGS}
CPPFLAGS+=              ${WX1MOTIF_CPPFLAGS}
LDFLAGS+=               ${WX1MOTIF_LDFLAGS}

.include "../../mk/motif.buildlink2.mk"

BUILDLINK_TARGETS+=	wx1Motif-buildlink

wx1Motif-buildlink: _BUILDLINK_USE

.endif	# WX1MOTIF_BUILDLINK2_MK
