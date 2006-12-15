# $NetBSD: buildlink3.mk,v 1.9 2006/12/15 20:33:04 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QT4_LIBS_BUILDLINK3_MK:=	${QT4_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qt4-libs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqt4-libs}
BUILDLINK_PACKAGES+=	qt4-libs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}qt4-libs

.if !empty(QT4_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.1.0
BUILDLINK_ABI_DEPENDS.qt4-libs+=	qt4-libs>=4.1.2nb1
BUILDLINK_PKGSRCDIR.qt4-libs?=	../../x11/qt4-libs

BUILDLINK_INCDIRS.qt4-libs+=	qt4/include
BUILDLINK_LIBDIRS.qt4-libs+=	qt4/lib
.endif	# QT4_LIBS_BUILDLINK3_MK

QTDIR=	${BUILDLINK_PREFIX.qt4-libs}/qt4
BUILDLINK_PASSTHRU_DIRS+=	${QTDIR}

PTHREAD_OPTS+=	require

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if !defined(BUILD_QT4)
CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}
.endif

CONFIGURE_ENV+=		MOC="${QTDIR}/bin/moc"
MAKE_ENV+=		MOC="${QTDIR}/bin/moc"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
