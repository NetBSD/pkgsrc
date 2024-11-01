# $NetBSD: buildlink3.mk,v 1.3 2024/11/01 12:54:50 wiz Exp $

BUILDLINK_TREE+=	kf6-syndication

.if !defined(KF6_SYNDICATION_BUILDLINK3_MK)
KF6_SYNDICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-syndication+=	kf6-syndication>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-syndication?=	kf6-syndication>=6.2.0nb3
BUILDLINK_PKGSRCDIR.kf6-syndication?=	../../www/kf6-syndication

.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_SYNDICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-syndication
