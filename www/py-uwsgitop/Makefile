# $NetBSD: Makefile,v 1.16 2024/11/11 07:29:28 wiz Exp $

DISTNAME=	uwsgitop-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uwsgitop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xrmx/uwsgitop
COMMENT=	Command to interface with the uWSGI stats server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uwsgitop uwsgitop-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
