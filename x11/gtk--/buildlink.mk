# $NetBSD: buildlink.mk,v 1.3 2002/09/11 21:53:47 wiz Exp $
#
# This Makefile fragment is included by packages that use gtk--.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtkmm to the dependency pattern
#     for the version of gtkmm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTKMM_BUILDLINK_MK)
GTKMM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtkmm?=	gtk-->=1.2.10
DEPENDS+=			${BUILDLINK_DEPENDS.gtkmm}:../../x11/gtk--

EVAL_PREFIX+=			BUILDLINK_PREFIX.gtkmm=gtkmm
BUILDLINK_PREFIX.gtkmm_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkmm=		include/gdk--.h
BUILDLINK_FILES.gtkmm+=		include/gdk--/*
BUILDLINK_FILES.gtkmm+=		include/glib--.h
BUILDLINK_FILES.gtkmm+=		include/gtk--.h
BUILDLINK_FILES.gtkmm+=		include/gtk--/*
BUILDLINK_FILES.gtkmm+=		lib/gtkmm/include/*
BUILDLINK_FILES.gtkmm+=		lib/libgdkmm.*
BUILDLINK_FILES.gtkmm+=		lib/libgtkmm.*

.include "../../devel/libsigc++/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.gtkmm=	gtkmm-buildlink
BUILDLINK_TARGETS.gtkmm+=	gtkmm-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gtkmm}

BUILDLINK_CONFIG.gtkmm=		${BUILDLINK_PREFIX.gtkmm}/bin/gtkmm-config
BUILDLINK_CONFIG_WRAPPER.gtkmm=	${BUILDLINK_DIR}/bin/gtkmm-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gtkmm}|${BUILDLINK_CONFIG.gtkmm}|g" \
	-e "s|-I${BUILDLINK_DIR}/\(lib/gtkmm/include\)|-I${BUILDLINK_PREFIX.gnome-libs}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.gtkmm}/\(lib/gtkmm/include\)|-I${BUILDLINK_DIR}/\1|g"

.if defined(USE_CONFIG_WRAPPER)
GTKMM_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gtkmm}
CONFIGURE_ENV+=		GTKMM_CONFIG="${GTKMM_CONFIG}"
MAKE_ENV+=		GTKMM_CONFIG="${GTKMM_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gtkmm}
gtkmm-buildlink: _BUILDLINK_USE
gtkmm-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GTKMM_BUILDLINK_MK
