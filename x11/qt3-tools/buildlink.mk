# $NetBSD: buildlink.mk,v 1.1.1.1 2002/01/07 08:09:16 skrll Exp $
#
# This Makefile fragment is included by packages that use qt3-tools.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.qt3-tools to the dependency
#     pattern for the version of qt3-tools desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(QT3_TOOLS_BUILDLINK_MK)
QT3_TOOLS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.qt3-tools?= qt3-tools>=3.0.1
DEPENDS+=	${BUILDLINK_DEPENDS.qt3-tools}:../../x11/qt3-tools

EVAL_PREFIX+=			BUILDLINK_PREFIX.qt3-tools=qt3-tools
BUILDLINK_PREFIX.qt3-tools=	${X11PREFIX}
BUILDLINK_FILES.qt3-tools=	qt3/bin/assistant
BUILDLINK_FILES.qt3-tools+=	qt3/bin/designer
BUILDLINK_FILES.qt3-tools+=	qt3/bin/linguist
BUILDLINK_FILES.qt3-tools+=	qt3/bin/qm2ts
BUILDLINK_FILES.qt3-tools+=	qt3/bin/qtconfig
BUILDLINK_FILES.qt3-tools+=	qt3/bin/uic
BUILDLINK_FILES.qt3-tools+=	qt3/lib/libeditor.*
BUILDLINK_FILES.qt3-tools+=	qt3/lib/libqui.*
BUILDLINK_FILES.qt3-tools+=	qt3/plugins/designer/libdlgplugin.*
BUILDLINK_FILES.qt3-tools+=	qt3/plugins/designer/librcplugin.*
BUILDLINK_FILES.qt3-tools+=	qt3/plugins/designer/libwizards.*
BUILDLINK_FILES.qt3-tools+=	qt3/plugins/imageformats/libqjpeg.*
BUILDLINK_FILES.qt3-tools+=	qt3/plugins/imageformats/libqmng.*

.include "../../x11/qt3-libs/buildlink.mk"

CONFIGURE_ENV+=			UIC="${BUILDLINK_QTDIR}/bin/uic"
MAKE_ENV+=			UIC="${BUILDLINK_QTDIR}/bin/uic"

BUILDLINK_TARGETS.qt3-tools=	qt3-tools-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.qt3-tools}

pre-configure: ${BUILDLINK_TARGETS.qt3-tools}
qt3-tools-buildlink: _BUILDLINK_USE

.endif	# QT3_TOOLS_BUILDLINK_MK
