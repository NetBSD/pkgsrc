# $NetBSD: Makefile,v 1.1 2023/10/04 21:01:58 adam Exp $

DISTNAME=	backports.zoneinfo-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.zoneinfo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pganssle/zoneinfo
COMMENT=	Backport of the standard library zoneinfo module
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	38 # included in Python 3.9

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
