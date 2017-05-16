# $NetBSD: Makefile,v 1.11 2017/05/16 09:27:52 adam Exp $

DISTNAME=	parsedatetime-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsedatetime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bear/parsedatetime
COMMENT=	Python module for parsing human-readable date/time text
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
