# $NetBSD: buildlink3.mk,v 1.59 2021/04/21 11:40:43 adam Exp $

BUILDLINK_TREE+=	libgtkhtml

.if !defined(LIBGTKHTML_BUILDLINK3_MK)
LIBGTKHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.0
BUILDLINK_ABI_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.3nb47
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtkhtml
