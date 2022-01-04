# $NetBSD: Makefile,v 1.7 2022/01/04 20:55:08 wiz Exp $

DISTNAME=	uritemplate-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uritemplate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/uritemplate/
COMMENT=	Python implementation of RFC6570, URI Template
LICENSE=	apache-2.0 OR modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
