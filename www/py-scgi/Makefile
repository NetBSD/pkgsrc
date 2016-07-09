# $NetBSD: Makefile,v 1.12 2016/07/09 13:04:15 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-quixote

.include "../../lang/python/distutils.mk"

.include "../../www/py-scgi/Makefile.common"
