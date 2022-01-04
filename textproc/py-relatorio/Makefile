# $NetBSD: Makefile,v 1.24 2022/01/04 20:55:05 wiz Exp $

DISTNAME=	relatorio-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relatorio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relatorio.tryton.org/
COMMENT=	Templating library able to output odt and pdf files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
