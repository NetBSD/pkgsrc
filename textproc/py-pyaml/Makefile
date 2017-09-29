# $NetBSD: Makefile,v 1.1 2017/09/29 13:45:04 joerg Exp $

DISTNAME=	pyaml-17.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mk-fg/pretty-yaml
COMMENT=	A YAML pretty printer for human readable output

# Strictly speaking, WTFPL
LICENSE=	public-domain

# Tests
BUILD_DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

do-test:
	cd ${WRKSRC}/pyaml/tests && py.test-${PYVERSSUFFIX} dump.py


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
