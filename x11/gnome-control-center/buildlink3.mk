# $NetBSD: buildlink3.mk,v 1.5 2009/08/26 19:56:46 sno Exp $

BUILDLINK_TREE+=	gnome-control-center

.if !defined(GNOME_CONTROL_CENTER_BUILDLINK3_MK)
GNOME_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-control-center+=	gnome-control-center>=2.20.0.1
BUILDLINK_ABI_DEPENDS.gnome-control-center?=	gnome-control-center>=2.26.0nb2
BUILDLINK_PKGSRCDIR.gnome-control-center?=	../../x11/gnome-control-center

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.endif # GNOME_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-control-center
