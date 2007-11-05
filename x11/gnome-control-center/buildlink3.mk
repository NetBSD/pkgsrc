# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/05 19:17:29 drochner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_CONTROL_CENTER_BUILDLINK3_MK:=	${GNOME_CONTROL_CENTER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-control-center
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-control-center}
BUILDLINK_PACKAGES+=	gnome-control-center
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-control-center

.if ${GNOME_CONTROL_CENTER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-control-center+=	gnome-control-center>=2.20.0.1
BUILDLINK_PKGSRCDIR.gnome-control-center?=	../../x11/gnome-control-center
.endif	# GNOME_CONTROL_CENTER_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
