# $NetBSD: Makefile,v 1.5 2012/10/28 06:31:01 asau Exp $
#

DISTNAME=	pendrell-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pendrell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pendrell.olix0r.net/
COMMENT=	HTTP/1.1 User Agent for the Programmable Web
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
