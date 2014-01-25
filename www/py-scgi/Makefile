# $NetBSD: Makefile,v 1.8 2014/01/25 10:30:29 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1

COMMENT=	Simple Common Gateway Interface

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-quixote

.include "../../lang/python/distutils.mk"

.include "../../www/py-scgi/Makefile.common"
