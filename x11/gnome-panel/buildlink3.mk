# $NetBSD: buildlink3.mk,v 1.51.2.1 2012/10/03 12:09:49 spz Exp $

BUILDLINK_TREE+=	gnome-panel

.if !defined(GNOME_PANEL_BUILDLINK3_MK)
GNOME_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-panel+=		gnome-panel>=2.12.1nb3
BUILDLINK_ABI_DEPENDS.gnome-panel+=	gnome-panel>=2.32.1nb18
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome-panel

pkgbase:= gnome-panel
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gnome-panel:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # GNOME_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-panel
