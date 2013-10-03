# $NetBSD: Makefile,v 1.47 2013/10/03 07:52:32 prlw1 Exp $

DISTNAME=	libxml2-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxml2/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.9/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}/python
NO_CONFIGURE=	YES

PYTHON_VERSIONS_INCLUDE_3X=	yes

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
