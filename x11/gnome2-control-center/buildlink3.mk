# $NetBSD: buildlink3.mk,v 1.8 2004/10/03 00:18:33 tv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME2_CONTROL_CENTER_BUILDLINK3_MK:=	${GNOME2_CONTROL_CENTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome2-control-center
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome2-control-center}
BUILDLINK_PACKAGES+=	gnome2-control-center

.if !empty(GNOME2_CONTROL_CENTER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome2-control-center+=	gnome2-control-center>=2.8.0
BUILDLINK_RECOMMENDED.gnome2-control-center+=	gnome2-control-center>=2.8.0nb1
BUILDLINK_PKGSRCDIR.gnome2-control-center?=	../../x11/gnome2-control-center
.endif	# GNOME2_CONTROL_CENTER_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
