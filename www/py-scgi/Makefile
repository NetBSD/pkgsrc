# $NetBSD: Makefile,v 1.13 2017/01/01 14:44:05 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-quixote

.include "../../lang/python/distutils.mk"

.include "../../www/py-scgi/Makefile.common"
