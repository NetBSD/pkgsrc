# $NetBSD: buildlink3.mk,v 1.46 2023/10/24 22:11:27 wiz Exp $

BUILDLINK_TREE+=	kdewebkit

.if !defined(KDEWEBKIT_BUILDLINK3_MK)
KDEWEBKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdewebkit+=	kdewebkit>=5.21.0
BUILDLINK_ABI_DEPENDS.kdewebkit?=	kdewebkit>=5.108.0nb1
BUILDLINK_PKGSRCDIR.kdewebkit?=		../../www/kdewebkit

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif	# KDEWEBKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdewebkit
