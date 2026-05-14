# $NetBSD: buildlink3.mk,v 1.4 2026/05/14 16:42:29 ryoon Exp $

BUILDLINK_TREE+=	plasma6-kdecoration

.if !defined(PLASMA6_KDECORATION_BUILDLINK3_MK)
PLASMA6_KDECORATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-kdecoration+=	plasma6-kdecoration>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-kdecoration?=	plasma6-kdecoration>=6.5.2nb3
BUILDLINK_PKGSRCDIR.plasma6-kdecoration?=	../../x11/plasma6-kdecoration

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_KDECORATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-kdecoration
