# $NetBSD: Makefile,v 1.1 2017/09/29 13:39:59 joerg Exp $

DISTNAME=	dicttoxml-1.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dicttoxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quandyfactory/dicttoxml
COMMENT=	Library for simple XML serialization
LICENSE=	gnu-gpl-v2

# No real tests
do-test:
	${NADA}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
