# $NetBSD: buildlink3.mk,v 1.7 2017/11/30 16:45:11 adam Exp $

BUILDLINK_TREE+=	kguiaddons

.if !defined(KGUIADDONS_BUILDLINK3_MK)
KGUIADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kguiaddons+=	kguiaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kguiaddons?=	kguiaddons>=5.25.0nb6
BUILDLINK_PKGSRCDIR.kguiaddons?=	../../x11/kguiaddons

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KGUIADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kguiaddons
