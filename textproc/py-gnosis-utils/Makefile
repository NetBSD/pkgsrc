# $NetBSD: Makefile,v 1.25 2024/04/17 10:38:36 wiz Exp $

DISTNAME=	Gnosis_Utils-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Gnosis_Utils/gnosis-utils/}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML
LICENSE=	public-domain

USE_LANGUAGES=	#none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.2

CONFLICTS+=	py[0-9]*-Gnosis-Utils-[0-9]*

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
