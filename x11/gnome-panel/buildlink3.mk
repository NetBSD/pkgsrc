# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:11:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-panel.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_PANEL_BUILDLINK3_MK:=	${GNOME_PANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-panel
.endif

.if !empty(GNOME_PANEL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-panel
BUILDLINK_DEPENDS.gnome-panel+=		gnome-panel>=2.4.1nb3
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome-panel

.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.endif # GNOME_PANEL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
