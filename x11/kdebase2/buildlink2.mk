# $NetBSD: buildlink2.mk,v 1.7 2002/10/26 13:09:07 bouyer Exp $

.if !defined(KDEBASE2_BUILDLINK2_MK)
KDEBASE2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		kdebase2
BUILDLINK_PKGBASE.kdebase2?=	kdebase
BUILDLINK_DEPENDS.kdebase2?=	kdebase>=2.2.2nb1
BUILDLINK_PKGSRCDIR.kdebase2?=	../../x11/kdebase2

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdebase2=kdebase
BUILDLINK_PREFIX.kdebase2_DEFAULT=	${X11PREFIX}
.if ${OPSYS} == "SunOS"
BUILDLINK_FILES_CMD.kdebase2= \
	${BUILDLINK_PLIST_CMD.kdebase2} | ${EGREP} '^(include|lib)'
.else
BUILDLINK_FILES_CMD.kdebase2= \
	${BUILDLINK_PLIST_CMD.kdebase2} | ${GREP} '^\(include\|lib\)'
.endif

.include "../../x11/kdelibs2/buildlink2.mk"

BUILDLINK_TARGETS+=	kdebase2-buildlink

kdebase2-buildlink: _BUILDLINK_USE

.endif	# KDEBASE2_BUILDLINK2_MK
