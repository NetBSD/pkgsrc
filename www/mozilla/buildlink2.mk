# $NetBSD: buildlink2.mk,v 1.10.2.1 2003/12/05 17:05:26 agc Exp $
#

.if !defined(MOZILLA_BUILDLINK2_MK)
MOZILLA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mozilla
BUILDLINK_DEPENDS.mozilla?=		mozilla>=1.5
BUILDLINK_PKGSRCDIR.mozilla?=		../../www/mozilla

EVAL_PREFIX+=	BUILDLINK_PREFIX.mozilla=mozilla
BUILDLINK_PREFIX.mozilla_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.mozilla+=	include/mozilla/*.h
BUILDLINK_FILES.mozilla+=	include/mozilla/*/*.h
BUILDLINK_FILES.mozilla+=	include/mozilla/*/*/*.h

BUILDLINK_FILES.mozilla+=	lib/mozilla/lib*.*

.include	"../../graphics/freetype2/buildlink2.mk"
.include	"../../graphics/gdk-pixbuf/buildlink2.mk"
.include	"../../graphics/jpeg/buildlink2.mk"
.include	"../../graphics/png/buildlink2.mk"
.include	"../../net/ORBit/buildlink2.mk"
.include	"../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	mozilla-buildlink

mozilla-buildlink: _BUILDLINK_USE

.endif	# MOZILLA_BUILDLINK2_MK
