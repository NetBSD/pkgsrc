# $NetBSD: buildlink3.mk,v 1.22 2023/11/08 13:21:12 wiz Exp $

BUILDLINK_TREE+=	kholidays

.if !defined(KHOLIDAYS_BUILDLINK3_MK)
KHOLIDAYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kholidays+=	kholidays>=5.44.0
BUILDLINK_ABI_DEPENDS.kholidays?=	kholidays>=5.108.0nb2
BUILDLINK_PKGSRCDIR.kholidays?=		../../time/kholidays

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KHOLIDAYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kholidays
