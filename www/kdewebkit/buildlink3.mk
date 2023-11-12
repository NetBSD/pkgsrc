# $NetBSD: buildlink3.mk,v 1.48 2023/11/12 13:23:55 wiz Exp $

BUILDLINK_TREE+=	kdewebkit

.if !defined(KDEWEBKIT_BUILDLINK3_MK)
KDEWEBKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdewebkit+=	kdewebkit>=5.21.0
BUILDLINK_ABI_DEPENDS.kdewebkit?=	kdewebkit>=5.108.0nb3
BUILDLINK_PKGSRCDIR.kdewebkit?=		../../www/kdewebkit

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif	# KDEWEBKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdewebkit
