# $NetBSD: buildlink3.mk,v 1.61 2020/03/10 22:09:17 wiz Exp $

BUILDLINK_TREE+=	xfce4-panel

.if !defined(XFCE4_PANEL_BUILDLINK3_MK)
XFCE4_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.13.3
BUILDLINK_ABI_DEPENDS.xfce4-panel+=	xfce4-panel>=4.14.3nb2
BUILDLINK_PKGSRCDIR.xfce4-panel?=	../../x11/xfce4-panel

.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.endif # XFCE4_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-panel
