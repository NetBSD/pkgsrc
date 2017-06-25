# $NetBSD: buildlink3.mk,v 1.1 2017/06/25 23:20:45 youri Exp $

BUILDLINK_TREE+=	vte

.if !defined(VTE_BUILDLINK3_MK)
VTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vte+=	vte>=0.38.0
BUILDLINK_ABI_DEPENDS.vte+=	vte>=0.38.0
BUILDLINK_PKGSRCDIR.vte?=	../../x11/vte

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.endif # VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte
