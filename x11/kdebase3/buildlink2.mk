# $NetBSD: buildlink2.mk,v 1.5 2002/10/12 09:00:36 jlam Exp $

.if !defined(KDEBASE3_BUILDLINK2_MK)
KDEBASE3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kdebase3
BUILDLINK_PKGBASE.kdebase3?=	kdebase
BUILDLINK_DEPENDS.kdebase3?=	kdebase>=3.0
BUILDLINK_PKGSRCDIR.kdebase3?=	../../x11/kdebase3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdebase3=kdebase
BUILDLINK_PREFIX.kdebase3_DEFAULT=	${X11PREFIX}
_KDEBASE3_BLNK_FILES= \
	${BUILDLINK_PLIST_CMD.kdebase3} | ${GREP} '^\(include\|lib\)'
BUILDLINK_FILES.kdebase3=	`${_KDEBASE3_BLNK_FILES}`

.include "../../x11/kdelibs3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdebase3-buildlink

kdebase3-buildlink: _BUILDLINK_USE

.endif	# KDEBASE3_BUILDLINK2_MK
