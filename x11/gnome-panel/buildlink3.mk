# $NetBSD: buildlink3.mk,v 1.29 2008/09/06 20:54:34 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PANEL_BUILDLINK3_MK:=	${GNOME_PANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-panel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-panel}
BUILDLINK_PACKAGES+=	gnome-panel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-panel

.if !empty(GNOME_PANEL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-panel+=		gnome-panel>=2.12.1nb3
BUILDLINK_ABI_DEPENDS.gnome-panel?=	gnome-panel>=2.22.2nb1
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome-panel

pkgbase:= gnome-panel
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gnome-panel:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
.endif	# GNOME_PANEL_BUILDLINK3_MK

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
