# $NetBSD: buildlink3.mk,v 1.29 2023/10/24 22:11:40 wiz Exp $

BUILDLINK_TREE+=	kwindowsystem

.if !defined(KWINDOWSYSTEM_BUILDLINK3_MK)
KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwindowsystem+=	kwindowsystem>=5.18.0
BUILDLINK_ABI_DEPENDS.kwindowsystem?=	kwindowsystem>=5.108.0nb1
BUILDLINK_PKGSRCDIR.kwindowsystem?=	../../x11/kwindowsystem


.include "../../mk/bsd.fast.prefs.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.else
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.endif	# KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwindowsystem
