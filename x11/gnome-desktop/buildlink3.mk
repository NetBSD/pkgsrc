# $NetBSD: buildlink3.mk,v 1.76 2024/10/20 14:04:46 wiz Exp $

BUILDLINK_TREE+=	gnome-desktop

.if !defined(GNOME_DESKTOP_BUILDLINK3_MK)
GNOME_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=44
BUILDLINK_ABI_DEPENDS.gnome-desktop?=	gnome-desktop>=44.0nb5
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.endif # GNOME_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-desktop
