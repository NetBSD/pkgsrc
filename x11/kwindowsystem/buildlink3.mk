# $NetBSD: buildlink3.mk,v 1.20 2020/11/05 09:07:16 ryoon Exp $

BUILDLINK_TREE+=	kwindowsystem

.if !defined(KWINDOWSYSTEM_BUILDLINK3_MK)
KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwindowsystem+=	kwindowsystem>=5.18.0
BUILDLINK_ABI_DEPENDS.kwindowsystem?=	kwindowsystem>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kwindowsystem?=	../../x11/kwindowsystem

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwindowsystem
