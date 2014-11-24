# $NetBSD: Makefile,v 1.10 2014/11/24 04:45:05 mef Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-quixote

.include "../../lang/python/distutils.mk"

.include "../../www/py-scgi/Makefile.common"
