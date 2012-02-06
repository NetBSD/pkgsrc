# $NetBSD: buildlink3.mk,v 1.19 2012/02/06 12:41:56 wiz Exp $

BUILDLINK_TREE+=	gnome-control-center

.if !defined(GNOME_CONTROL_CENTER_BUILDLINK3_MK)
GNOME_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-control-center+=	gnome-control-center>=2.20.0.1
BUILDLINK_ABI_DEPENDS.gnome-control-center?=	gnome-control-center>=2.32.1nb8
BUILDLINK_PKGSRCDIR.gnome-control-center?=	../../x11/gnome-control-center

.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.endif # GNOME_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-control-center
