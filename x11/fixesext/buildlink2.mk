# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/16 08:39:24 recht Exp $
#

.if !defined(FIXESEXT_BUILDLINK2_MK)
FIXESEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fixesext
BUILDLINK_DEPENDS.fixesext?=		fixesext>=2.0
BUILDLINK_PKGSRCDIR.fixesext?=		../../x11/fixesext

EVAL_PREFIX+=	BUILDLINK_PREFIX.fixesext=fixesext
BUILDLINK_PREFIX.fixesext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fixesext+=	include/X11/extensions/xfixesproto.h
BUILDLINK_FILES.fixesext+=	include/X11/extensions/xfixeswire.h

USE_X11=	yes

BUILDLINK_TARGETS+=	fixesext-buildlink

fixesext-buildlink: _BUILDLINK_USE

.endif	# FIXESEXT_BUILDLINK2_MK
