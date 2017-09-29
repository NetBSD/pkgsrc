# $NetBSD: Makefile,v 1.1 2017/09/29 14:39:35 joerg Exp $

DISTNAME=	meinheld-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meinheld/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meinheld.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.5<0.5:../../devel/py-greenlet

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
