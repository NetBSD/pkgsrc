# $NetBSD: buildlink3.mk,v 1.3 2008/10/24 20:59:54 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_DESKTOP_SHARP_BUILDLINK3_MK:=	${GNOME_DESKTOP_SHARP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-desktop-sharp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-desktop-sharp}
BUILDLINK_PACKAGES+=	gnome-desktop-sharp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-desktop-sharp

.if ${GNOME_DESKTOP_SHARP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-desktop-sharp+=	gnome-desktop-sharp>=2.24.0
BUILDLINK_PKGSRCDIR.gnome-desktop-sharp?=	../../x11/gnome-desktop-sharp
.endif	# GNOME_DESKTOP_SHARP_BUILDLINK3_MK

.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
