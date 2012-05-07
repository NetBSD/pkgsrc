# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:54:09 dholland Exp $

BUILDLINK_TREE+=	gtkglarea

.if !defined(GTKGLAREA_BUILDLINK3_MK)
GTKGLAREA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkglarea+=	gtkglarea>=1.2.2nb3
BUILDLINK_ABI_DEPENDS.gtkglarea+=	gtkglarea>=1.2.3nb3
BUILDLINK_PKGSRCDIR.gtkglarea?=	../../x11/gtkglarea

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif # GTKGLAREA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglarea
