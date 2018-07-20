# $NetBSD: buildlink3.mk,v 1.17 2018/07/20 03:33:57 ryoon Exp $

BUILDLINK_TREE+=	kdewebkit

.if !defined(KDEWEBKIT_BUILDLINK3_MK)
KDEWEBKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdewebkit+=	kdewebkit>=5.21.0
BUILDLINK_ABI_DEPENDS.kdewebkit?=	kdewebkit>=5.47.0nb3
BUILDLINK_PKGSRCDIR.kdewebkit?=		../../www/kdewebkit

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif	# KDEWEBKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdewebkit
