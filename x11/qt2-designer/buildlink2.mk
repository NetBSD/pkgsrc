# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:32 jlam Exp $
#
# This Makefile fragment is included by packages that use qt2-designer.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.qt2-designer to the dependency
#     pattern for the version of qt2-designer desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(QT2_DESIGNER_BUILDLINK2_MK)
QT2_DESIGNER_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.qt2-designer?= \
		{qt2-designer>=2.3.1nb2,qt2-designer-kde>=2.3.1nb2}
DEPENDS+=	${BUILDLINK_DEPENDS.qt2-designer}:../../x11/qt2-designer

EVAL_PREFIX+=	BUILDLINK_PREFIX.qt2-designer=qt2-designer
BUILDLINK_PREFIX.qt2-designer_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt2-designer=	qt2/bin/designer
BUILDLINK_FILES.qt2-designer+=	qt2/bin/uic
BUILDLINK_FILES.qt2-designer+=	qt2/lib/libqutil.*

.include "../../x11/qt2-libs/buildlink2.mk"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
MAKE_ENV+=		UIC="${QTDIR}/bin/uic"

BUILDLINK_TARGETS+=	qt2-designer-buildlink

qt2-designer-buildlink: _BUILDLINK_USE

.endif	# QT2_DESIGNER_BUILDLINK2_MK
