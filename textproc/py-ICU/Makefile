# $NetBSD: Makefile,v 1.1 2020/02/09 21:11:29 jdolecek Exp $

DISTNAME=	PyICU-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyICU/ICU/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyICU/}

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://github.com/ovalhub/pyicu
COMMENT=	Python extension wrapping the ICU C++ libraries
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
