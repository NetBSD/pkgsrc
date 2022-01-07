# $NetBSD: Makefile,v 1.8 2022/01/07 11:46:58 tnn Exp $

DISTNAME=	pandocfilters-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandocfilters/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgm/pandocfilters
COMMENT=	Utilities for writing pandoc filters in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} == "py27"
_PYSETUPTOOLSINSTALLARGS:=	${_PYSETUPTOOLSINSTALLARGS:N--single-version-externally-managed}
.endif

.include "../../mk/bsd.pkg.mk"
