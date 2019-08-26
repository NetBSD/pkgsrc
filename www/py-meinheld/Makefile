# $NetBSD: Makefile,v 1.4 2019/08/26 13:41:17 adam Exp $

DISTNAME=	meinheld-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meinheld/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://meinheld.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.5:../../devel/py-greenlet

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
