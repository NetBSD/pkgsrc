# $NetBSD: buildlink3.mk,v 1.39 2022/08/11 05:09:25 gutteridge Exp $

BUILDLINK_TREE+=	frameworkintegration

.if !defined(FRAMEWORKINTEGRATION_BUILDLINK3_MK)
FRAMEWORKINTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frameworkintegration+=	frameworkintegration>=5.21.0
BUILDLINK_ABI_DEPENDS.frameworkintegration?=	frameworkintegration>=5.93.0nb2
BUILDLINK_PKGSRCDIR.frameworkintegration?=	../../x11/frameworkintegration

.include "../../devel/kpackage/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# FRAMEWORKINTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-frameworkintegration
