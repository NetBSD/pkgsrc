# $NetBSD: Makefile,v 1.49.6.1 2014/11/03 19:39:08 tron Exp $

DISTNAME=	libxml2-2.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxml2/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.9/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/python
NO_CONFIGURE=	YES

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "/ROOT/s,'/usr','${BUILDLINK_PREFIX.libxml2}',g"
SUBST_SED.setup+=	-e "/^\"/s,/usr/include,${BUILDLINK_PREFIX.iconv}/include,g"
SUBST_SED.setup+=	-e "/^\"/s,/usr/local/include,${BUILDLINK_PREFIX.iconv}/include,g"

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=${PKGVERSION}
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
