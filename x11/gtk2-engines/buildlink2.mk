# $NetBSD: buildlink2.mk,v 1.4 2004/04/01 19:02:34 jmmv Exp $
#
# This Makefile fragment is included by packages that use gtk2-engines.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GTK2_ENGINES_BUILDLINK2_MK)
GTK2_ENGINES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtk2-engines
BUILDLINK_DEPENDS.gtk2-engines?=	gtk2-engines>=2.2.0nb6
BUILDLINK_PKGSRCDIR.gtk2-engines?=	../../x11/gtk2-engines

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtk2-engines=gtk2-engines
BUILDLINK_PREFIX.gtk2-engines_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk2-engines+=	lib/pkgconfig/gtk-engines-2.pc

.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk2-engines-buildlink

gtk2-engines-buildlink: _BUILDLINK_USE

.endif	# GTK2_ENGINES_BUILDLINK2_MK
