# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:05 wiz Exp $

DISTNAME=		sgmllib3k-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=s/sgmllib3k/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://hg.hardcoded.net/sgmllib
COMMENT=		Py3k port of sgmllib
LICENSE=		2-clause-bsd

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
