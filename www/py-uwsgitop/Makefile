# $NetBSD: Makefile,v 1.5 2014/05/03 19:07:55 rodent Exp $

DISTNAME=	uwsgitop-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/u/uwsgitop/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi/wiki/StatsServer
COMMENT=	Command to interface with the uWSGI stats server
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-uwsgi-[0-9]*:../../www/py-uwsgi
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/uwsgitop \
		${DESTDIR}${PREFIX}/bin/uwsgitop${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
