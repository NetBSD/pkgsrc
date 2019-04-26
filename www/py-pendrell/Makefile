# $NetBSD: Makefile,v 1.15 2019/04/26 13:14:21 maya Exp $

DISTNAME=	pendrell-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pendrell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pendrell.olix0r.net/
COMMENT=	HTTP/1.1 User Agent for the Programmable Web
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.2.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
