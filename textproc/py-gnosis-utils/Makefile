# $NetBSD: Makefile,v 1.23 2022/01/10 09:10:43 wiz Exp $

DISTNAME=	Gnosis_Utils-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Gnosis_Utils/gnosis-utils/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	#none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.2

CONFLICTS+=	${PYPKGPREFIX}-Gnosis-Utils-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
