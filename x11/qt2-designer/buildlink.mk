# $NetBSD: buildlink.mk,v 1.8 2002/01/06 10:37:43 skrll Exp $
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

.if !defined(QT2_DESIGNER_BUILDLINK_MK)
QT2_DESIGNER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.qt2-designer?= \
		{qt2-designer>=2.2.4,qt2-designer-kde>=2.3.1nb1}
DEPENDS+=	${BUILDLINK_DEPENDS.qt2-designer}:../../x11/qt2-designer

EVAL_PREFIX+=			BUILDLINK_PREFIX.qt2-designer=qt2-designer
BUILDLINK_PREFIX.qt2-designer_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt2-designer=	qt2/bin/designer
BUILDLINK_FILES.qt2-designer+=	qt2/bin/uic
BUILDLINK_FILES.qt2-designer+=	qt2/lib/libqutil.*

.include "../../x11/qt2-libs/buildlink.mk"

CONFIGURE_ENV+=			UIC="${BUILDLINK_QTDIR}/bin/uic"
MAKE_ENV+=			UIC="${BUILDLINK_QTDIR}/bin/uic"

BUILDLINK_TARGETS.qt2-designer=	qt2-designer-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.qt2-designer}

pre-configure: ${BUILDLINK_TARGETS.qt2-designer}
qt2-designer-buildlink: _BUILDLINK_USE

.endif	# QT2_DESIGNER_BUILDLINK_MK
