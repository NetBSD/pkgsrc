# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:41:17 martti Exp $
#
# This Makefile fragment is included by packages that use libxfce4util.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBXFCE4UTIL_BUILDLINK2_MK)
LIBXFCE4UTIL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libxfce4util
BUILDLINK_DEPENDS.libxfce4util?=		libxfce4util>=4.0.0
BUILDLINK_PKGSRCDIR.libxfce4util?=		../../x11/libxfce4util

EVAL_PREFIX+=	BUILDLINK_PREFIX.libxfce4util=libxfce4util
BUILDLINK_PREFIX.libxfce4util_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libxfce4util+=	include/xfce4/libxfce4util/debug.h
BUILDLINK_FILES.libxfce4util+=	include/xfce4/libxfce4util/i18n.h
BUILDLINK_FILES.libxfce4util+=	include/xfce4/libxfce4util/utf8.h
BUILDLINK_FILES.libxfce4util+=	include/xfce4/libxfce4util/util.h
BUILDLINK_FILES.libxfce4util+=	lib/libxfce4util.*
BUILDLINK_FILES.libxfce4util+=	lib/pkgconfig/libxfce4util-1.0.pc

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	libxfce4util-buildlink

libxfce4util-buildlink: _BUILDLINK_USE

.endif	# LIBXFCE4UTIL_BUILDLINK2_MK
