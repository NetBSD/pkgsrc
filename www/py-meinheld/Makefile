# $NetBSD: Makefile,v 1.6 2022/01/04 20:55:31 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
