# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:52 jlam Exp $

.if !defined(KDEBASE2_BUILDLINK2_MK)
KDEBASE2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kdebase2
BUILDLINK_DEPENDS.kdebase2?=	kdebase>=2.2.2nb1
BUILDLINK_PKGSRCDIR.kdebase2?=	../../x11/kdebase2

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdebase2=kdebase
BUILDLINK_PREFIX.kdebase2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdebase2!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdebase2/PLIST

.include "../../x11/kdelibs2/buildlink2.mk"

BUILDLINK_TARGETS+=	kdebase2-buildlink

kdebase2-buildlink: _BUILDLINK_USE

.endif	# KDEBASE2_BUILDLINK2_MK
