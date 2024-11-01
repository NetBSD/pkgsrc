# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:54:17 wiz Exp $

BUILDLINK_TREE+=	kf6-ktextwidgets

.if !defined(KF6_KTEXTWIDGETS_BUILDLINK3_MK)
KF6_KTEXTWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-ktextwidgets+=	kf6-ktextwidgets>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-ktextwidgets?=		kf6-ktextwidgets>=6.2.0nb2
BUILDLINK_PKGSRCDIR.kf6-ktextwidgets?=		../../x11/kf6-ktextwidgets

.include "../../audio/qt6-qtspeech/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../textproc/kf6-sonnet/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KTEXTWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-ktextwidgets
