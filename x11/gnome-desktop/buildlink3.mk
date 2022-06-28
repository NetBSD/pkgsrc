# $NetBSD: buildlink3.mk,v 1.65 2022/06/28 11:37:52 wiz Exp $

BUILDLINK_TREE+=	gnome-desktop

.if !defined(GNOME_DESKTOP_BUILDLINK3_MK)
GNOME_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=2.30.0
BUILDLINK_ABI_DEPENDS.gnome-desktop+=	gnome-desktop>=2.32.1nb49
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # GNOME_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-desktop
