# $NetBSD: Makefile,v 1.13 2017/09/04 18:01:03 wiz Exp $

DISTNAME=	pendrell-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pendrell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pendrell.olix0r.net/
COMMENT=	HTTP/1.1 User Agent for the Programmable Web
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.2.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
