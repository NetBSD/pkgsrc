# $NetBSD: buildlink3.mk,v 1.1 2004/04/26 04:55:29 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PANEL_BUILDLINK3_MK:=	${GNOME_PANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-panel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-panel}
BUILDLINK_PACKAGES+=	gnome-panel

.if !empty(GNOME_PANEL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-panel?=         gnome-panel>=1.4.2nb5
BUILDLINK_RECOMMENDED.gnome-panel?=             gnome-panel>=1.4.2nb8
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../x11/gnome1-panel
.endif	# GNOME_PANEL_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/gnome-pixmaps/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
