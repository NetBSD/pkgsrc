# $NetBSD: buildlink2.mk,v 1.4 2003/11/12 01:31:53 salo Exp $
#
# This Makefile fragment is included by packages that use gnome-session.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_SESSION_BUILDLINK2_MK)
GNOME_SESSION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-session
BUILDLINK_DEPENDS.gnome-session?=		gnome-session>=1.4.2nb3
BUILDLINK_PKGSRCDIR.gnome-session?=		../../x11/gnome1-session

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-session=gnome-session
BUILDLINK_PREFIX.gnome-session_DEFAULT=	${X11PREFIX}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/gnome-pixmaps/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-session-buildlink

gnome-session-buildlink: _BUILDLINK_USE

.endif	# GNOME_SESSION_BUILDLINK2_MK
