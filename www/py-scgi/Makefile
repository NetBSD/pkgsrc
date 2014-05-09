# $NetBSD: Makefile,v 1.9 2014/05/09 07:37:26 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1

COMMENT=	Simple Common Gateway Interface

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-quixote

.include "../../lang/python/distutils.mk"

.include "../../www/py-scgi/Makefile.common"
