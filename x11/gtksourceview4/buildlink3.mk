# $NetBSD: buildlink3.mk,v 1.14 2022/08/11 05:09:27 gutteridge Exp $

BUILDLINK_TREE+=	gtksourceview4

.if !defined(GTKSOURCEVIEW4_BUILDLINK3_MK)
GTKSOURCEVIEW4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview4+=	gtksourceview4>=4.0.0
BUILDLINK_ABI_DEPENDS.gtksourceview4?=	gtksourceview4>=4.8.0nb6
BUILDLINK_PKGSRCDIR.gtksourceview4?=	../../x11/gtksourceview4

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKSOURCEVIEW4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview4
