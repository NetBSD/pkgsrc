# $NetBSD: buildlink2.mk,v 1.2 2004/01/09 23:05:01 cube Exp $

.if !defined(ION_BUILDLINK2_MK)
ION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ion
BUILDLINK_DEPENDS.ion?=		ion>=20031211
BUILDLINK_PKGSRCDIR.ion?=	../../wm/ion-devel

EVAL_PREFIX+=			BUILDLINK_PREFIX.ion=ion
BUILDLINK_PREFIX.ion_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ion=		include/ion/*.h
BUILDLINK_FILES.ion+=		include/ion/mkexports.lua
BUILDLINK_FILES.ion+=		include/ion/*.mk
BUILDLINK_FILES.ion+=		include/ion/ioncore/*.h
BUILDLINK_FILES.ion+=		include/ion/libtu/*.h
BUILDLINK_FILES.ion+=		include/ion/luaextl/*.h

BUILDLINK_TARGETS+=		ion-buildlink

ion-buildlink: _BUILDLINK_USE

.endif	# ION_BUILDLINK2_MK
