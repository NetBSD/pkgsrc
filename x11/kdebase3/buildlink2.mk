# $NetBSD: buildlink2.mk,v 1.15 2003/12/08 14:41:42 wiz Exp $

.if !defined(KDEBASE3_BUILDLINK2_MK)
KDEBASE3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kdebase3
BUILDLINK_PKGBASE.kdebase3?=	kdebase
BUILDLINK_DEPENDS.kdebase3?=	kdebase>=3.1.4nb2
BUILDLINK_PKGSRCDIR.kdebase3?=	../../x11/kdebase3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdebase3=kdebase
BUILDLINK_PREFIX.kdebase3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.kdebase3= \
	${BUILDLINK_PLIST_CMD.kdebase3} | ${GREP} '^\(include\|lib\)'

.include "../../x11/kdelibs3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdebase3-buildlink

kdebase3-buildlink: _BUILDLINK_USE

.endif	# KDEBASE3_BUILDLINK2_MK
