# $NetBSD: Makefile,v 1.1 2020/10/13 10:36:11 schmonz Exp $

DISTNAME=		sgmllib3k-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
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
