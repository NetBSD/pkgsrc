# $NetBSD: buildlink2.mk,v 1.9 2003/11/12 01:31:52 salo Exp $
#
# This Makefile fragment is included by packages that use gnome-core.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_CORE_BUILDLINK2_MK)
GNOME_CORE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-core
BUILDLINK_DEPENDS.gnome-core?=		gnome-core>=1.4.2nb8
BUILDLINK_PKGSRCDIR.gnome-core?=		../../x11/gnome-core

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-core=gnome-core
BUILDLINK_PREFIX.gnome-core_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-core+=	lib/libfish_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libgen_util_applet.*

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/gnome-pixmaps/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/gnome1-panel/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-core-buildlink

gnome-core-buildlink: _BUILDLINK_USE

.endif	# GNOME_CORE_BUILDLINK2_MK
