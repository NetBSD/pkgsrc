# $NetBSD: buildlink3.mk,v 1.2 2004/11/30 18:26:41 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_SESSION_BUILDLINK3_MK:=	${GNOME_SESSION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-session
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-session}
BUILDLINK_PACKAGES+=	gnome-session

.if !empty(GNOME_SESSION_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-session?=	gnome-session>=1.4.2nb11
BUILDLINK_PKGSRCDIR.gnome-session?=	../../x11/gnome1-session
.endif	# GNOME_SESSION_BUILDLINK3_MK

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
