# $NetBSD: buildlink3.mk,v 1.34 2023/01/03 17:36:36 wiz Exp $

BUILDLINK_TREE+=	gtksourceview3

.if !defined(GTKSOURCEVIEW3_BUILDLINK3_MK)
GTKSOURCEVIEW3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview3+=	gtksourceview3>=3.4.2
BUILDLINK_ABI_DEPENDS.gtksourceview3?=	gtksourceview3>=3.24.11nb11
BUILDLINK_PKGSRCDIR.gtksourceview3?=	../../x11/gtksourceview3

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTKSOURCEVIEW3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview3
