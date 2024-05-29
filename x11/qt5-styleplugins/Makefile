# $NetBSD: Makefile,v 1.17 2024/05/29 16:35:14 adam Exp $

DISTNAME=	qt5-styleplugins-5.0.0.20170112
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=qt/}
GITHUB_PROJECT=	qtstyleplugins
GITHUB_TAG=	335dbece103e2cbf6c7cf819ab6672c2956b17b3

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/qt/qtstyleplugins
COMMENT=	Qt 5 extra widget styles
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
        ${SETENV} ${CONFIGURE_ENV} \
        ${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
