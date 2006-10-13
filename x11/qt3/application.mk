# $NetBSD: application.mk,v 1.1 2006/10/13 06:16:54 rillig Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# work-around bug noted in PR #25402
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-undefined
.endif

.if ${OPSYS} == "SunOS"
GCC_REQD+=		3.3
.endif

QTDIR?=			${PREFIX}/qt3

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--disable-rpath
.if exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--with-xinerama
.endif

CONFIGURE_ENV+=		USER_LDFLAGS=${LDFLAGS:M*:Q}
LDFLAGS+=		-L${QTDIR}/lib

CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.endif
