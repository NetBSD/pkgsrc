# $NetBSD
#
# This Makefile fragment is included by packages that use qt3-libs.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.qt3-libs to the dependency pattern
#     for the version of qt3-libs desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(QT3_LIBS_BUILDLINK_MK)
QT3_LIBS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.qt3-libs?=	qt3-libs>=3.0.1
DEPENDS+=			${BUILDLINK_DEPENDS.qt3-libs}:../../x11/qt3-libs

EVAL_PREFIX+=			BUILDLINK_PREFIX.qt3-libs=qt3-libs
BUILDLINK_PREFIX.qt3-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt3-libs=	qt3/bin/moc
BUILDLINK_FILES.qt3-libs+=	qt3/include/*.h
BUILDLINK_FILES.qt3-libs+=	qt3/include/private/*.h
BUILDLINK_FILES.qt3-libs+=	qt3/lib/libqt.*

REAL_QTDIR=			${BUILDLINK_PREFIX.qt3-libs}/qt3
BUILDLINK_QTDIR=		${BUILDLINK_DIR}/qt3
REPLACE_BUILDLINK_SED+=		-e "s|-I${BUILDLINK_QTDIR}/|-I${REAL_QTDIR}/|g"
REPLACE_BUILDLINK_SED+=		-e "s|-L${BUILDLINK_QTDIR}/|-L${REAL_QTDIR}/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	-e "s|-I${REAL_QTDIR}/|-I${BUILDLINK_QTDIR}/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	-e "s|-L${REAL_QTDIR}/|-L${BUILDLINK_QTDIR}/|g"

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/mng/buildlink.mk"
.include "../../graphics/png/buildlink.mk"

CONFIGURE_ENV+=			MOC="${BUILDLINK_QTDIR}/bin/moc"
MAKE_ENV+=			MOC="${BUILDLINK_QTDIR}/bin/moc"
LDFLAGS+=			-Wl,-R${REAL_QTDIR}/lib

BUILDLINK_TARGETS.qt3-libs=	qt3-libs-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.qt3-libs}

pre-configure: ${BUILDLINK_TARGETS.qt3-libs}
qt3-libs-buildlink: _BUILDLINK_USE

.endif	# QT3_LIBS_BUILDLINK_MK
