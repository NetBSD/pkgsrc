# $NetBSD: buildlink2.mk,v 1.2 2002/09/20 02:06:08 jlam Exp $

.if !defined(KDEBASE2_BUILDLINK2_MK)
KDEBASE2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		kdebase2
BUILDLINK_DEPENDS.kdebase2?=	kdebase>=2.2.2nb1
BUILDLINK_PKGSRCDIR.kdebase2?=	../../x11/kdebase2

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdebase2=kdebase
BUILDLINK_PREFIX.kdebase2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdebase2!=						\
	${GREP} "^\(include\|lib\)"					\
		${.CURDIR}/${BUILDLINK_PKGSRCDIR.kdebase2}/PLIST

.include "../../x11/kdelibs2/buildlink2.mk"

BUILDLINK_TARGETS+=	kdebase2-buildlink

kdebase2-buildlink: _BUILDLINK_USE

.endif	# KDEBASE2_BUILDLINK2_MK
