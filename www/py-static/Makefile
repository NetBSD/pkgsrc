# $NetBSD: Makefile,v 1.1 2014/08/20 13:44:58 wiz Exp $

DISTNAME=	static-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/s/static/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/static
COMMENT=	Serve static or templated content via WSGI or stand-alone
LICENSE=	mit

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/static ${DESTDIR}${PREFIX}/bin/static-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
