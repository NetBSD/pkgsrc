# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:54 jlam Exp $

.if !defined(QT2_DESIGNER_BUILDLINK2_MK)
QT2_DESIGNER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			qt2-designer
BUILDLINK_PKGBASE.qt2-designer?=	qt2-designer{,-kde}
BUILDLINK_DEPENDS.qt2-designer?=	\
		{qt2-designer>=2.3.1nb2,qt2-designer-kde>=2.3.1nb2}
BUILDLINK_PKGSRCDIR.qt2-designer?=	../../x11/qt2-designer

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
