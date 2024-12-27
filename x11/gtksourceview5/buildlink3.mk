# $NetBSD: buildlink3.mk,v 1.9 2024/12/27 08:20:57 wiz Exp $

BUILDLINK_TREE+=	gtksourceview5

.if !defined(GTKSOURCEVIEW5_BUILDLINK3_MK)
GTKSOURCEVIEW5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview5+=	gtksourceview5>=5.0.0
BUILDLINK_ABI_DEPENDS.gtksourceview5?=	gtksourceview5>=5.10.0nb9
BUILDLINK_PKGSRCDIR.gtksourceview5?=	../../x11/gtksourceview5

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# GTKSOURCEVIEW5_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview5
