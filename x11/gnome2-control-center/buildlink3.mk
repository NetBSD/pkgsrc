# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:11:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome2-control-center.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME2_CONTROL_CENTER_BUILDLINK3_MK:=	${GNOME2_CONTROL_CENTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome2-control-center
.endif

.if !empty(GNOME2_CONTROL_CENTER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome2-control-center
BUILDLINK_DEPENDS.gnome2-control-center+=	gnome2-control-center>=2.4.0nb2
BUILDLINK_PKGSRCDIR.gnome2-control-center?=	../../x11/gnome2-control-center

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.endif # GNOME2_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
