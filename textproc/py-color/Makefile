# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:52 wiz Exp $

DISTNAME=	color-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=c/color/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahchandler/color
COMMENT=	Very small color printing module
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
