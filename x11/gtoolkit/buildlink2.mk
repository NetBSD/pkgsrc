# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/11/09 05:19:28 rh Exp $
#
# This Makefile fragment is included by packages that use gtoolkit.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(GTOOLKIT_BUILDLINK2_MK)
GTOOLKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtoolkit
BUILDLINK_DEPENDS.gtoolkit?=		gtoolkit>=0.9.5
BUILDLINK_PKGSRCDIR.gtoolkit?=		../../x11/gtoolkit

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtoolkit=gtoolkit
BUILDLINK_PREFIX.gtoolkit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtoolkit+=	share/GNUstep/Local/Headers/GToolKit/*.h
BUILDLINK_FILES.gtoolkit+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libGToolKit.*

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"

BUILDLINK_TARGETS+=	gtoolkit-buildlink

gtoolkit-buildlink: _BUILDLINK_USE

.endif	# GTOOLKIT_BUILDLINK2_MK
