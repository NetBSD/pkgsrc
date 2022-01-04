# $NetBSD: Makefile,v 1.12 2022/01/04 20:55:37 wiz Exp $

DISTNAME=	uwsgitop-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uwsgitop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uwsgi-docs.readthedocs.io/
COMMENT=	Command to interface with the uWSGI stats server
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uwsgitop uwsgitop-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
