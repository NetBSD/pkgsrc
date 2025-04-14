# $NetBSD: Makefile,v 1.17 2025/04/14 20:28:03 adam Exp $

DISTNAME=	uwsgitop-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uwsgitop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xrmx/uwsgitop
COMMENT=	Command to interface with the uWSGI stats server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uwsgitop uwsgitop-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
