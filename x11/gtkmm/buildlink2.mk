# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/01 14:33:09 jmmv Exp $
#
# This Makefile fragment is included by packages that use gtkmm.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GTKMM_BUILDLINK2_MK)
GTKMM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkmm
BUILDLINK_DEPENDS.gtkmm?=		gtkmm>=2.2.0
BUILDLINK_PKGSRCDIR.gtkmm?=		../../x11/gtkmm

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkmm=gtkmm
BUILDLINK_PREFIX.gtkmm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/atkmm/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/atkmm/private/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/gdkmm/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/gdkmm/private/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/glibmm/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/glibmm/private/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/gtkmm/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/gtkmm/private/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/gtkmm_generate_extra_defs/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/pangomm/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/pangomm/private/*
BUILDLINK_FILES.gtkmm+=	include/gtkmm-2.0/pangomm/wrap_init.h
BUILDLINK_FILES.gtkmm+=	lib/gtkmm-2.0/include/*
BUILDLINK_FILES.gtkmm+=	lib/gtkmm-2.0/proc/*
BUILDLINK_FILES.gtkmm+=	lib/gtkmm-2.0/proc/m4/*
BUILDLINK_FILES.gtkmm+=	lib/gtkmm-2.0/proc/pm/*
BUILDLINK_FILES.gtkmm+=	lib/libatkmm-1.0.*
BUILDLINK_FILES.gtkmm+=	lib/libgdkmm-2.0.*
BUILDLINK_FILES.gtkmm+=	lib/libglibmm-2.0.*
BUILDLINK_FILES.gtkmm+=	lib/libgtkmm-2.0.*
BUILDLINK_FILES.gtkmm+=	lib/libgtkmm_generate_extra_defs-2.0.*
BUILDLINK_FILES.gtkmm+=	lib/libpangomm-1.0.*
BUILDLINK_FILES.gtkmm+=	lib/pkgconfig/atkmm-1.0.pc
BUILDLINK_FILES.gtkmm+=	lib/pkgconfig/gdkmm-2.0.pc
BUILDLINK_FILES.gtkmm+=	lib/pkgconfig/glibmm-2.0.pc
BUILDLINK_FILES.gtkmm+=	lib/pkgconfig/gtkmm-2.0.pc
BUILDLINK_FILES.gtkmm+=	lib/pkgconfig/pangomm-1.0.pc

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkmm-buildlink

gtkmm-buildlink: _BUILDLINK_USE

.endif	# GTKMM_BUILDLINK2_MK
