# $NetBSD: buildlink.mk,v 1.9 2001/07/27 13:33:38 jlam Exp $
#
# This Makefile fragment is included by packages that use qt2-libs.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.qt2-libs to the dependency pattern
#     for the version of qt2-libs desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(QT2_LIBS_BUILDLINK_MK)
QT2_LIBS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.qt2-libs?=	qt2-libs>=2.2.4
DEPENDS+=	${BUILDLINK_DEPENDS.qt2-libs}:../../x11/qt2-libs

EVAL_PREFIX+=			BUILDLINK_PREFIX.qt2-libs=qt2-libs
BUILDLINK_PREFIX.qt2-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt2-libs=	qt2/bin/moc
BUILDLINK_FILES.qt2-libs+=	qt2/include/*.h
BUILDLINK_FILES.qt2-libs+=	qt2/lib/libqt.*

BUILDLINK_QTDIR=		${BUILDLINK_DIR}/qt2
QTDIR=				${BUILDLINK_PREFIX.qt2-libs}/qt2
REPLACE_BUILDLINK_SED+=		-e "s|-I${BUILDLINK_QTDIR}/|-I${QTDIR}/|g"
REPLACE_BUILDLINK_SED+=		-e "s|-L${BUILDLINK_QTDIR}/|-L${QTDIR}/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	-e "s|-I${QTDIR}/|-I${BUILDLINK_QTDIR}/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	-e "s|-L${QTDIR}/|-L${BUILDLINK_QTDIR}/|g"

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/mng/buildlink.mk"
.include "../../graphics/png/buildlink.mk"

CONFIGURE_ENV+=			QTDIR="${BUILDLINK_QTDIR}"
CONFIGURE_ENV+=			MOC="${BUILDLINK_QTDIR}/bin/moc"
MAKE_ENV+=			QTDIR="${BUILDLINK_QTDIR}"
MAKE_ENV+=			MOC="${BUILDLINK_QTDIR}/bin/moc"
LDFLAGS+=			-Wl,-R${QTDIR}/lib

BUILDLINK_TARGETS.qt2-libs=	qt2-libs-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.qt2-libs}

pre-configure: ${BUILDLINK_TARGETS.qt2-libs}
qt2-libs-buildlink: _BUILDLINK_USE

.endif	# QT2_LIBS_BUILDLINK_MK
