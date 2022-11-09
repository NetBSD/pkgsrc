# $NetBSD: Makefile,v 1.18 2022/11/09 13:14:18 joerg Exp $

DISTNAME=		swish-e-0.5
PKGNAME=		${PYPKGPREFIX}-swish-e-0.5
PKGREVISION=		3
CATEGORIES=		www python
MASTER_SITES=		http://download.berlios.de/py-swish-e/

WRKSRC=			${WRKDIR}/SwishE-0.5

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://py-swish-e.berlios.de/
COMMENT=		Simple Python binding for Swish-E
LICENSE=		2-clause-bsd

EGG_NAME=		SwishE-${PKGVERSION_NOREV}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.5

.include "../../lang/python/egg.mk"
.include "../../www/swish-e/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
