# $NetBSD: buildlink2.mk,v 1.8 2004/04/01 18:35:00 jmmv Exp $
#
# This Makefile fragment is included by packages that use gtksourceview.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GTKSOURCEVIEW_BUILDLINK2_MK)
GTKSOURCEVIEW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtksourceview
BUILDLINK_DEPENDS.gtksourceview?=		gtksourceview>=1.0.0
BUILDLINK_PKGSRCDIR.gtksourceview?=		../../x11/gtksourceview

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtksourceview=gtksourceview
BUILDLINK_PREFIX.gtksourceview_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtksourceview+=	include/gtksourceview-1.0/gtksourceview/*
BUILDLINK_FILES.gtksourceview+=	lib/libgtksourceview-1.0.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtksourceview-buildlink

gtksourceview-buildlink: _BUILDLINK_USE

.endif	# GTKSOURCEVIEW_BUILDLINK2_MK
