# $NetBSD: buildlink3.mk,v 1.1 2004/04/25 00:17:32 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_CORE_BUILDLINK3_MK:=	${GNOME_CORE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-core
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-core}
BUILDLINK_PACKAGES+=	gnome-core

.if !empty(GNOME_CORE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-core+=		gnome-core>=1.4.2nb10
BUILDLINK_RECOMMENDED.gnome-core+=	gnome-core>=1.4.2nb13
BUILDLINK_PKGSRCDIR.gnome-core?=	../../x11/gnome-core
.endif	# GNOME_CORE_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/gnome-pixmaps/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../x11/gnome1-session/buildlink3.mk"
.include "../../x11/gnome1-panel/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
