# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/21 23:00:43 jlam Exp $

.if !defined(QT2_LIBS_BUILDLINK2_MK)
QT2_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		qt2-libs
BUILDLINK_DEPENDS.qt2-libs?=	qt2-libs>=2.3.1nb2
BUILDLINK_PKGSRCDIR.qt2-libs?=	../../x11/qt2-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.qt2-libs=qt2-libs
BUILDLINK_PREFIX.qt2-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt2-libs+=	qt2/include/*.h
BUILDLINK_FILES.qt2-libs+=	qt2/lib/libqt.*

QTDIR=		${BUILDLINK_PREFIX.qt2-libs}/qt2

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

CONFIGURE_ENV+=		QTDIR="${QTDIR}"
CONFIGURE_ENV+=		MOC="${QTDIR}/bin/moc"
MAKE_ENV+=		QTDIR="${QTDIR}"
MAKE_ENV+=		MOC="${QTDIR}/bin/moc"
LDFLAGS+=		-Wl,-R${QTDIR}/lib

BUILDLINK_TARGETS+=	qt2-libs-buildlink

qt2-libs-buildlink: _BUILDLINK_USE

.endif	# QT2_LIBS_BUILDLINK2_MK
