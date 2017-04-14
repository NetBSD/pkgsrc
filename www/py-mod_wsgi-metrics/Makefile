# $NetBSD: Makefile,v 1.3 2017/04/14 18:12:24 adam Exp $

DISTNAME=	mod_wsgi-metrics-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mod_wsgi-metrics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modwsgi.org/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-psutil>=2.0.0:../../sysutils/py-psutil

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
