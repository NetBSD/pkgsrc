# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:47:10 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-desktop.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_DESKTOP_BUILDLINK3_MK:=	${GNOME_DESKTOP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-desktop
.endif

.if !empty(GNOME_DESKTOP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-desktop
BUILDLINK_DEPENDS.gnome-desktop+=	gnome-desktop>=2.4.1.1nb2
BUILDLINK_PKGSRCDIR.gnome-desktop?=	../../x11/gnome-desktop

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/gnome2-pixmaps/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.endif # GNOME_DESKTOP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
