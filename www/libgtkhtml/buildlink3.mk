# $NetBSD: buildlink3.mk,v 1.82 2026/09/02 19:04:59 wiz Exp $

BUILDLINK_TREE+=	libgtkhtml

.if !defined(LIBGTKHTML_BUILDLINK3_MK)
LIBGTKHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.0
BUILDLINK_ABI_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.3nb72
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtkhtml
