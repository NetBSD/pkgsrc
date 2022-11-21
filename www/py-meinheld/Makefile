# $NetBSD: Makefile,v 1.7 2022/11/21 11:31:57 adam Exp $

DISTNAME=	meinheld-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meinheld/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://meinheld.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.5:../../devel/py-greenlet

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-greenlet

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
