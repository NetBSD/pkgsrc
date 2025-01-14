# $NetBSD: Makefile,v 1.29 2025/01/14 16:52:18 adam Exp $

DISTNAME=	relatorio-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relatorio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relatorio.tryton.org/
COMMENT=	Templating library able to output odt and pdf files
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} relatorio-render relatorio-render-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
