# $NetBSD: buildlink.mk,v 1.5 2002/09/10 16:06:51 wiz Exp $
#
# This Makefile fragment is included by packages that use gtkhtml.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtkhtml to the dependency pattern
#     for the version of gtkhtml desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTKHTML_BUILDLINK_MK)
GTKHTML_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtkhtml?=		gtkhtml>=1.0.1nb2
DEPENDS+=	${BUILDLINK_DEPENDS.gtkhtml}:../../www/gtkhtml

EVAL_PREFIX+=			BUILDLINK_PREFIX.gtkhtml=gtkhtml
BUILDLINK_PREFIX.gtkhtml_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkhtml+=		include/gtkhtml/*
BUILDLINK_FILES.gtkhtml+=		lib/bonobo/libstorage_http.*
BUILDLINK_FILES.gtkhtml+=		lib/libgtkhtml.*

.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../www/glibwww/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"

BUILDLINK_TARGETS.gtkhtml=		gtkhtml-buildlink
BUILDLINK_TARGETS.gtkhtml+=		gtkhtml-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gtkhtml}

BUILDLINK_CONFIG.gtkhtml=		${BUILDLINK_PREFIX.gtkhtml}/lib/gtkhtmlConf.sh
BUILDLINK_CONFIG_WRAPPER.gtkhtml=	${BUILDLINK_DIR}/lib/gtkhtmlConf.sh

.if defined(USE_CONFIG_WRAPPER)
GTKHTML_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gtkhtml}
CONFIGURE_ENV+=		GTKHTML_CONFIG="${GTKHTML_CONFIG}"
MAKE_ENV+=		GTKHTML_CONFIG="${GTKHTML_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gtkhtml}
gtkhtml-buildlink: _BUILDLINK_USE
gtkhtml-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GTKHTML_BUILDLINK_MK
