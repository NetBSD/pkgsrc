# $NetBSD: Makefile,v 1.14 2019/04/26 13:14:22 maya Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.5

.include "../../lang/python/distutils.mk"
.include "../../www/swish-e/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
