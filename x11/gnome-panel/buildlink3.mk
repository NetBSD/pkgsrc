# $NetBSD: buildlink3.mk,v 1.12 2006/01/24 07:32:51 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PANEL_BUILDLINK3_MK:=	${GNOME_PANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-panel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-panel}
BUILDLINK_PACKAGES+=	gnome-panel

.if !empty(GNOME_PANEL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-panel+=		gnome-panel>=2.12.1nb3
BUILDLINK_RECOMMENDED.gnome-panel?=	gnome-panel>=2.12.2nb1
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome-panel
.endif	# GNOME_PANEL_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
