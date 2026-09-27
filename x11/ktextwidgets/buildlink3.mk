# $NetBSD: buildlink3.mk,v 1.56 2026/09/27 11:39:23 tnn Exp $

BUILDLINK_TREE+=	ktextwidgets

.if !defined(KTEXTWIDGETS_BUILDLINK3_MK)
KTEXTWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktextwidgets+=	ktextwidgets>=5.19.0
BUILDLINK_ABI_DEPENDS.ktextwidgets?=	ktextwidgets>=5.116.0nb11
BUILDLINK_PKGSRCDIR.ktextwidgets?=	../../x11/ktextwidgets

.include "../../devel/kservice/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../textproc/sonnet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtspeech/buildlink3.mk"
.endif	# KTEXTWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktextwidgets
