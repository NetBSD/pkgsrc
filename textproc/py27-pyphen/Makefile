# $NetBSD: Makefile,v 1.5 2023/08/14 05:25:24 wiz Exp $

DISTNAME=	Pyphen-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyphen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyphen.org/
COMMENT=	Pure Python module to hyphenate text
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
