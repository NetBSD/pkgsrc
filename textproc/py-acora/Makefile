# $NetBSD: Makefile,v 1.11 2022/11/14 14:11:43 wiz Exp $

DISTNAME=	acora-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scoder/acora
COMMENT=	Fast multi-keyword search engine for text strings in Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

# 2.3 distfile does not support python 3.11
post-extract:
	${RM} ${WRKSRC}/acora/*.c
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} acora

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
