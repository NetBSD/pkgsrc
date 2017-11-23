# $NetBSD: buildlink3.mk,v 1.3 2017/11/23 17:19:46 wiz Exp $

BUILDLINK_TREE+=	vte

.if !defined(VTE_BUILDLINK3_MK)
VTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vte+=	vte>=0.38.0
BUILDLINK_ABI_DEPENDS.vte+=	vte>=0.38.4nb1
BUILDLINK_PKGSRCDIR.vte?=	../../x11/vte3

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.endif # VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte
