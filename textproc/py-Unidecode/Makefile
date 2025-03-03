# $NetBSD: Makefile,v 1.19 2025/03/03 06:58:21 wiz Exp $

DISTNAME=	Unidecode-1.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=U/Unidecode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/avian2/unidecode
COMMENT=	ASCII transliterations of Unicode text
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/U/u/}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} unidecode unidecode-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
