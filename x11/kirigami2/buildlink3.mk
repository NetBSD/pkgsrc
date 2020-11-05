# $NetBSD: buildlink3.mk,v 1.15 2020/11/05 09:07:16 ryoon Exp $

BUILDLINK_TREE+=	kirigami2

.if !defined(KIRIGAMI2_BUILDLINK3_MK)
KIRIGAMI2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kirigami2+=	kirigami2>=5.41.0
BUILDLINK_ABI_DEPENDS.kirigami2?=	kirigami2>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kirigami2?=		../../x11/kirigami2

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KIRIGAMI2_BUILDLINK3_MK

BUILDLINK_TREE+=	-kirigami2
