# $NetBSD: buildlink3.mk,v 1.36 2023/01/03 17:36:35 wiz Exp $

BUILDLINK_TREE+=	gnome-desktop3

.if !defined(GNOME_DESKTOP3_BUILDLINK3_MK)
GNOME_DESKTOP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop3+=	gnome-desktop3>=3.4.2
BUILDLINK_ABI_DEPENDS.gnome-desktop3+=	gnome-desktop3>=40.5nb3
BUILDLINK_PKGSRCDIR.gnome-desktop3?=	../../x11/gnome-desktop3

BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.27.0
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gnome-desktop3
