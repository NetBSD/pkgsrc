# $NetBSD: Makefile,v 1.8 2017/01/03 13:23:05 jperkin Exp $

DISTNAME=	uwsgitop-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uwsgitop/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi/wiki/StatsServer
COMMENT=	Command to interface with the uWSGI stats server
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-uwsgi-[0-9]*:../../www/py-uwsgi
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/uwsgitop \
		${DESTDIR}${PREFIX}/bin/uwsgitop${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
