# $NetBSD: Makefile,v 1.1 2016/02/16 13:49:56 leot Exp $

DISTNAME=	h2-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=3.2.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.1.0:../../net/py-hpack

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
