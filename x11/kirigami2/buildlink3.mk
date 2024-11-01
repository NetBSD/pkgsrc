# $NetBSD: buildlink3.mk,v 1.27 2024/11/01 00:54:18 wiz Exp $

BUILDLINK_TREE+=	kirigami2

.if !defined(KIRIGAMI2_BUILDLINK3_MK)
KIRIGAMI2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kirigami2+=	kirigami2>=5.41.0
BUILDLINK_ABI_DEPENDS.kirigami2?=	kirigami2>=5.116.0nb1
BUILDLINK_PKGSRCDIR.kirigami2?=		../../x11/kirigami2

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KIRIGAMI2_BUILDLINK3_MK

BUILDLINK_TREE+=	-kirigami2
