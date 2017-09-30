# $NetBSD: Makefile,v 1.3 2017/09/30 21:52:06 wiz Exp $

DISTNAME=	meinheld-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meinheld/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meinheld.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.5<0.5:../../devel/py-greenlet
# needed for tests, optional at runtime
BUILD_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
