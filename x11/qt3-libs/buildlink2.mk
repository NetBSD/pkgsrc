# $NetBSD

.if !defined(QT3_LIBS_BUILDLINK2_MK)
QT3_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		qt3-libs
BUILDLINK_DEPENDS.qt3-libs?=	qt3-libs>=3.0.4nb1
BUILDLINK_PKGSRCDIR.qt3-libs?=	../../x11/qt3-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.qt3-libs=qt3-libs
BUILDLINK_PREFIX.qt3-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt3-libs+=	qt3/include/*.h
BUILDLINK_FILES.qt3-libs+=	qt3/include/private/*.h
BUILDLINK_FILES.qt3-libs+=	qt3/lib/libqt-mt.*

QTDIR=		${BUILDLINK_PREFIX.qt3-libs}/qt3

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

BUILDLINK_TARGETS+=	qt3-libs-buildlink

qt3-libs-buildlink: _BUILDLINK_USE

.endif	# QT3_LIBS_BUILDLINK2_MK
