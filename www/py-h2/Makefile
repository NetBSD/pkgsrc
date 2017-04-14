# $NetBSD: Makefile,v 1.4 2017/04/14 13:10:13 leot Exp $

DISTNAME=	h2-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=3.1:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.2:../../net/py-hpack

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
