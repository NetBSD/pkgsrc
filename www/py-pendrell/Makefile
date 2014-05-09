# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:25 wiz Exp $

DISTNAME=	pendrell-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pendrell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pendrell.olix0r.net/
COMMENT=	HTTP/1.1 User Agent for the Programmable Web
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
