# $NetBSD: Makefile,v 1.4 2004/02/12 16:22:51 minskim Exp $

DISTNAME=	libxml2-python-${LIBXML_VERSION}
PKGNAME=	${PYPKGPREFIX}-libxslt-1.1.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/python/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	Python wrapper for libxslt

DEPENDS+=	${PYPKGPREFIX}-libxml2>=${LIBXML_VERSION}:../../textproc/py-libxml2

PYDISTUTILSPKG=	YES
USE_BUILDLINK3=	YES
NO_CONFIGURE=	YES

LIBXML_VERSION=	2.6.4

MAKE_ENV+=	PYLIBXSLTVERSION=${PKGVERSION}

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	"Fixing hardcoded paths."
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,'/usr','${BUILDLINK_PREFIX.libxslt}',g"

BUILDLINK_DEPENDS.libxslt=	libxslt>=${PKGVERSION}
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
