# $NetBSD: buildlink3.mk,v 1.9 2026/11/11 11:56:41 wiz Exp $

BUILDLINK_TREE+=	plasma6-kdecoration

.if !defined(PLASMA6_KDECORATION_BUILDLINK3_MK)
PLASMA6_KDECORATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-kdecoration+=	plasma6-kdecoration>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-kdecoration?=	plasma6-kdecoration>=6.7.4nb4
BUILDLINK_PKGSRCDIR.plasma6-kdecoration?=	../../x11/plasma6-kdecoration

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_KDECORATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-kdecoration
