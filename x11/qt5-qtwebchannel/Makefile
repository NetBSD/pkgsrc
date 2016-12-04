# $NetBSD: Makefile,v 1.12 2016/12/04 05:17:16 ryoon Exp $

DISTNAME=	qtwebchannel-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtwebchannel-${QTVERSION}
PKGREVISION=	5
COMMENT=	Qt5 WebChannel module

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5WebChannel.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
