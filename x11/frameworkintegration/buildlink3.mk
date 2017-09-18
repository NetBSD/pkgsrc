# $NetBSD: buildlink3.mk,v 1.11 2017/09/18 09:53:06 maya Exp $

BUILDLINK_TREE+=	frameworkintegration

.if !defined(FRAMEWORKINTEGRATION_BUILDLINK3_MK)
FRAMEWORKINTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frameworkintegration+=	frameworkintegration>=5.21.0
BUILDLINK_ABI_DEPENDS.frameworkintegration?=	frameworkintegration>=5.25.0nb10
BUILDLINK_PKGSRCDIR.frameworkintegration?=	../../x11/frameworkintegration

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# FRAMEWORKINTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-frameworkintegration
