# $NetBSD: Makefile,v 1.12 2017/09/04 18:01:04 wiz Exp $

DISTNAME=		swish-e-0.5
PKGNAME=		${PYPKGPREFIX}-swish-e-0.5
PKGREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		http://download.berlios.de/py-swish-e/

WRKSRC=			${WRKDIR}/SwishE-0.5

MAINTAINER=		joerg@NetBSD.org
#HOMEPAGE=		http://py-swish-e.berlios.de/
COMMENT=		Simple Python binding for Swish-E
LICENSE=		2-clause-bsd

EGG_NAME=		SwishE-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.5

.include "../../lang/python/distutils.mk"
.include "../../www/swish-e/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
