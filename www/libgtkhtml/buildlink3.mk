# $NetBSD: buildlink3.mk,v 1.69 2024/04/07 07:35:12 wiz Exp $

BUILDLINK_TREE+=	libgtkhtml

.if !defined(LIBGTKHTML_BUILDLINK3_MK)
LIBGTKHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.0
BUILDLINK_ABI_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.3nb58
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtkhtml
