# $NetBSD: Makefile,v 1.4 2018/04/11 12:38:33 markd Exp $

DISTNAME=	qtquickcontrols2-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols2-${QTVERSION}
PKGREVISION=	2
COMMENT=	Next generation user interface controls based on Qt Quick

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5QuickControls2.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
