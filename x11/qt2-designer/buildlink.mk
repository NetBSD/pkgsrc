# $NetBSD: buildlink.mk,v 1.1 2001/06/23 19:28:22 jlam Exp $
#
# This Makefile fragment is included by packages that use qt2-designer.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.qt2-designer to the dependency
#     pattern for the version of qt2-designer desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(QT2_LIBS_BUILDLINK_MK)
QT2_LIBS_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.qt2-designer?=	qt2-designer>=2.2.4
DEPENDS+=	${BUILDLINK_DEPENDS.qt2-designer}:../../x11/qt2-designer

BUILDLINK_PREFIX.qt2-designer=	${X11PREFIX}
BUILDLINK_FILES.qt2-designer=	qt2/bin/designer
BUILDLINK_FILES.qt2-designer=	qt2/bin/uic
BUILDLINK_FILES.qt2-designer+=	qt2/lib/libqutil.*

.include "../../x11/qt2-libs/buildlink.mk"

BUILDLINK_TARGETS.qt2-designer=	qt2-designer-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.qt2-designer}

pre-configure: ${BUILDLINK_TARGETS.qt2-designer}
qt2-designer-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# QT2_LIBS_BUILDLINK_MK
