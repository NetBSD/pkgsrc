# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:42 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PANEL_BUILDLINK3_MK:=	${GNOME_PANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-panel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-panel}
BUILDLINK_PACKAGES+=	gnome-panel

.if !empty(GNOME_PANEL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-panel+=		gnome-panel>=2.4.1nb3
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome-panel

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.endif	# GNOME_PANEL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
