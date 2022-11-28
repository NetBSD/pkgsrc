# $NetBSD: Makefile,v 1.5 2022/11/28 13:26:24 adam Exp $

DISTNAME=	dicttoxml-1.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dicttoxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quandyfactory/dicttoxml
COMMENT=	Library for simple XML serialization
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

# No real tests
do-test:
	${NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
