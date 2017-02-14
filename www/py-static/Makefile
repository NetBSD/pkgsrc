# $NetBSD: Makefile,v 1.5 2017/02/14 07:35:06 adam Exp $

DISTNAME=	static-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=s/static/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/static
COMMENT=	Serve static or templated content via WSGI or stand-alone
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pystache-[0-9]*:../../www/py-pystache

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/static ${DESTDIR}${PREFIX}/bin/static-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
