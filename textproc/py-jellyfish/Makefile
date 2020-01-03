# $NetBSD: Makefile,v 1.5 2020/01/03 08:37:56 adam Exp $

DISTNAME=	jellyfish-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jellyfish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jamesturk/jellyfish
COMMENT=	Python library for doing approximate and phonetic matching of strings
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
