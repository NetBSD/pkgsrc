# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/30 17:55:33 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-mag.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(GNOME_MAG_BUILDLINK2_MK)
GNOME_MAG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-mag
BUILDLINK_DEPENDS.gnome-mag?=		gnome-mag>=0.10.4
BUILDLINK_PKGSRCDIR.gnome-mag?=		../../x11/gnome-mag

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-mag=gnome-mag
BUILDLINK_PREFIX.gnome-mag_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-mag+=	include/gnome-mag-1.0/magnifier/GNOME_Magnifier.h
BUILDLINK_FILES.gnome-mag+=	lib/bonobo/servers/GNOME_Magnifier.server
BUILDLINK_FILES.gnome-mag+=	lib/libgnome-mag.*

.include "../../devel/at-spi/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-mag-buildlink

gnome-mag-buildlink: _BUILDLINK_USE

.endif	# GNOME_MAG_BUILDLINK2_MK
