# $NetBSD: buildlink2.mk,v 1.6 2003/11/12 01:31:52 salo Exp $
#
# This Makefile fragment is included by packages that use libgtkhtml.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(LIBGTKHTML_BUILDLINK2_MK)
LIBGTKHTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgtkhtml
BUILDLINK_DEPENDS.libgtkhtml?=		libgtkhtml>=2.2.1nb3
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgtkhtml=libgtkhtml
BUILDLINK_PREFIX.libgtkhtml_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgtkhtml=	include/gtkhtml-2.0/libgtkhtml/css/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/document/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/core/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/events/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/html/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/traversal/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/views/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/dom/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/graphics/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/layout/html/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/layout/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/util/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/view/*
BUILDLINK_FILES.libgtkhtml+=	include/gtkhtml-2.0/libgtkhtml/*
BUILDLINK_FILES.libgtkhtml+=	lib/libgtkhtml-2.*
BUILDLINK_FILES.libgtkhtml+=	lib/pkgconfig/libgtkhtml-2.0.pc

.include "../../devel/gail/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgtkhtml-buildlink

libgtkhtml-buildlink: _BUILDLINK_USE

.endif	# LIBGTKHTML_BUILDLINK2_MK
