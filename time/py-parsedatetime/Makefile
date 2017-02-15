# $NetBSD: Makefile,v 1.9 2017/02/15 00:53:26 joerg Exp $

DISTNAME=	parsedatetime-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_GITHUB:=bear/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bear/parsedatetime
COMMENT=	Python module for parsing human-readable date/time text
LICENSE=	apache-2.0

GITHUB_PROJECT=	parsedatetime
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
