# $NetBSD: buildlink2.mk,v 1.5.2.1 2003/12/05 19:15:10 agc Exp $
#

.if !defined(MOZILLA_STABLE_BUILDLINK2_MK)
MOZILLA_STABLE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=				mozilla-stable
BUILDLINK_DEPENDS.mozilla-stable?=		mozilla-stable>=1.4.1
BUILDLINK_PKGSRCDIR.mozilla-stable?=		../../www/mozilla-stable

EVAL_PREFIX+=	BUILDLINK_PREFIX.mozilla-stable=mozilla-stable
BUILDLINK_PREFIX.mozilla-stable_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.mozilla-stable+=	include/mozilla-stable/*.h
BUILDLINK_FILES.mozilla-stable+=	include/mozilla-stable/*/*.h
BUILDLINK_FILES.mozilla-stable+=	include/mozilla-stable/*/*/*.h

BUILDLINK_FILES.mozilla-stable+=	lib/mozilla-stable/lib*.*

.include	"../../graphics/freetype2/buildlink2.mk"
.include	"../../graphics/gdk-pixbuf/buildlink2.mk"
.include	"../../graphics/jpeg/buildlink2.mk"
.include	"../../graphics/png/buildlink2.mk"
.include	"../../net/ORBit/buildlink2.mk"
.include	"../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	mozilla-stable-buildlink

mozilla-stable-buildlink: _BUILDLINK_USE

.endif	# MOZILLA_STABLE_BUILDLINK2_MK
