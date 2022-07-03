# $NetBSD: Makefile,v 1.1 2022/07/03 20:43:53 pin Exp $

DISTNAME=	qt5-styleplugins-5.0.0.20170112
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=qt/}
GITHUB_PROJECT=	qtstyleplugins
GITHUB_TAG=	335dbece103e2cbf6c7cf819ab6672c2956b17b3

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/qt/qtstyleplugins
COMMENT=	Qt 5 extra widget styles
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
        ${SETENV} ${CONFIGURE_ENV} \
        ${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
