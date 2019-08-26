# $NetBSD: Makefile,v 1.18 2019/08/26 15:13:29 adam Exp $

DISTNAME=	relatorio-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relatorio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relatorio.tryton.org/
COMMENT=	Templating library able to output odt and pdf files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
