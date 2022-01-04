# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:02 wiz Exp $

DISTNAME=	pyaml-18.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mk-fg/pretty-yaml
COMMENT=	YAML pretty printer for human readable output
# Strictly speaking, WTFPL
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
