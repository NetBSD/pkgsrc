# $NetBSD: Makefile,v 1.8 2015/12/05 21:26:06 adam Exp $

DISTNAME=	pendrell-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pendrell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pendrell.olix0r.net/
COMMENT=	HTTP/1.1 User Agent for the Programmable Web
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
