# $NetBSD: buildlink2.mk,v 1.12 2004/02/13 19:37:26 jmmv Exp $
#
# This Makefile fragment is included by packages that use libgtkhtml.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(LIBGTKHTML_BUILDLINK2_MK)
LIBGTKHTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgtkhtml
BUILDLINK_DEPENDS.libgtkhtml?=		libgtkhtml>=2.4.1nb2
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgtkhtml=libgtkhtml
BUILDLINK_PREFIX.libgtkhtml_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgtkhtml=	include/gtkhtml-2.0/libgtkhtml/*/*/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/*/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/*
BUILDLINK_FILES.libgtkhtml+=	lib/libgtkhtml-2.*

.include "../../devel/gail/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgtkhtml-buildlink

libgtkhtml-buildlink: _BUILDLINK_USE

.endif	# LIBGTKHTML_BUILDLINK2_MK
