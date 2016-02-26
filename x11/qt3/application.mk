# $NetBSD: application.mk,v 1.4 2016/02/26 11:27:16 jperkin Exp $
#
# This file provides useful definitions for packages that contain
# QT applications.
#
# It defines the following variables:
#
# QTDIR
#	The directory where qt3 is installed. This is not ${PREFIX} to
#	allow qt4 being installed at the same time.
#

.if !defined(QT3_APPLICATION_MK)
QT3_APPLICATION_MK=	# defined

# work-around bug noted in PR #25402
BUILDLINK_TRANSFORM.Linux+=	rm:-Wl,--no-undefined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
GCC_REQD+=		3.3
.endif

QTDIR?=			${PREFIX}/qt3

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--disable-rpath
.if exists(${X11BASE}/lib/libXinerama.so) || ${X11_TYPE} != "native"
CONFIGURE_ARGS+=	--with-xinerama
.include "../../x11/libXinerama/buildlink3.mk"
.endif

CONFIGURE_ENV+=		USER_LDFLAGS=${LDFLAGS:M*:Q}
LDFLAGS+=		-L${QTDIR}/lib

CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}

.for t in moc qmake uic
TOOLS_CREATE+=		${t}
TOOLS_PATH.${t}=	${QTDIR}/bin/${t}
.endfor

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.endif
