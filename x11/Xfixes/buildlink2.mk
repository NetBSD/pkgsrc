# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/16 08:40:51 recht Exp $

.if !defined(XFIXES_BUILDLINK2_MK)
XFIXES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Xfixes
BUILDLINK_DEPENDS.Xfixes?=		Xfixes>=2.0.0
BUILDLINK_PKGSRCDIR.Xfixes?=		../../x11/Xfixes

EVAL_PREFIX+=	BUILDLINK_PREFIX.Xfixes=Xfixes
BUILDLINK_PREFIX.Xfixes_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Xfixes+=	include/X11/extensions/Xfixes.h
BUILDLINK_FILES.Xfixes+=	lib/libXfixes.*

USE_X11=	yes

.include "../../x11/fixesext/buildlink2.mk"

BUILDLINK_TARGETS+=	Xfixes-buildlink

Xfixes-buildlink: _BUILDLINK_USE

.endif	# XFIXES_BUILDLINK2_MK
