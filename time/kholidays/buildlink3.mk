# $NetBSD: buildlink3.mk,v 1.10 2020/04/12 08:28:08 adam Exp $

BUILDLINK_TREE+=	kholidays

.if !defined(KHOLIDAYS_BUILDLINK3_MK)
KHOLIDAYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kholidays+=	kholidays>=5.44.0
BUILDLINK_ABI_DEPENDS.kholidays?=	kholidays>=5.66.0nb3
BUILDLINK_PKGSRCDIR.kholidays?=		../../time/kholidays

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KHOLIDAYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kholidays
