# $NetBSD: buildlink.mk,v 1.3 2001/07/02 04:40:38 jlam Exp $
#
# This Makefile fragment is included by packages that use wxGTK.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.wxGTK to the dependency pattern
#     for the version of wxGTK desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(WXGTK_BUILDLINK_MK)
WXGTK_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.wxGTK?=	wxGTK>=2.2.2
DEPENDS+=			${BUILDLINK_DEPENDS.wxGTK}:../../x11/wxGTK

BUILDLINK_PREFIX.wxGTK=		${X11PREFIX}
BUILDLINK_FILES.wxGTK=		include/wx/*
BUILDLINK_FILES.wxGTK+=		include/wx/*/*
BUILDLINK_FILES.wxGTK+=		lib/wx/include/wx/gtk/*
BUILDLINK_FILES.wxGTK+=		lib/libwx_gtk.*

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.wxGTK=	wxGTK-buildlink
BUILDLINK_TARGETS.wxGTK+=	wxGTK-1-buildlink-config-wrapper
BUILDLINK_TARGETS.wxGTK+=	wxGTK-2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.wxGTK}

BUILDLINK_CONFIG.wxGTK-1=		${X11PREFIX}/bin/wx-config
BUILDLINK_CONFIG.wxGTK-2=		${X11PREFIX}/bin/wxgtk-config
BUILDLINK_CONFIG_WRAPPER.wxGTK-1=	${BUILDLINK_DIR}/bin/wx-config
BUILDLINK_CONFIG_WRAPPER.wxGTK-2=	${BUILDLINK_DIR}/bin/wxgtk-config

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/\(include/wx/\)|${X11PREFIX}/\1|g"	\
	-e "s|-I${BUILDLINK_DIR}/\(lib/wx/include/\)|${X11PREFIX}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${X11PREFIX}/\(include/wx/\)|-I${BUILDLINK_DIR}/\1|g"	\
	-e "s|-I${X11PREFIX}/\(lib/wx/include/\)|-I${BUILDLINK_DIR}/\1|g"

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		WX_CONFIG="${BUILDLINK_CONFIG_WRAPPER.wxGTK-1}"
CONFIGURE_ENV+=		WXGTK_CONFIG="${BUILDLINK_CONFIG_WRAPPER.wxGTK-2}"
.endif

pre-configure: ${BUILDLINK_TARGETS.wxGTK}
wxGTK-buildlink: _BUILDLINK_USE
wxGTK-1-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
wxGTK-2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# WXGTK_BUILDLINK_MK
