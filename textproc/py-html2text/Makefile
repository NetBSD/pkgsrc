# $NetBSD: Makefile,v 1.66 2025/04/19 20:03:44 wiz Exp $

DISTNAME=	html2text-2025.4.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html2text/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://alir3z4.github.io/html2text/
COMMENT=	Convert HTML into easy-to-read plain ASCII text
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} html2text html2text-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
