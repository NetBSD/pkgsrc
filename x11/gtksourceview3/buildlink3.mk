# $NetBSD: buildlink3.mk,v 1.33 2022/11/23 16:19:07 adam Exp $

BUILDLINK_TREE+=	gtksourceview3

.if !defined(GTKSOURCEVIEW3_BUILDLINK3_MK)
GTKSOURCEVIEW3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview3+=	gtksourceview3>=3.4.2
BUILDLINK_ABI_DEPENDS.gtksourceview3?=	gtksourceview3>=3.24.11nb10
BUILDLINK_PKGSRCDIR.gtksourceview3?=	../../x11/gtksourceview3

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKSOURCEVIEW3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview3
