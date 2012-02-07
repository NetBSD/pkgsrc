# $NetBSD: Makefile,v 1.40 2012/02/07 11:21:51 obache Exp $

DISTNAME=	libxml2-2.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxml2/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.7/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/python
NO_CONFIGURE=	YES

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "/ROOT/s,'/usr','${BUILDLINK_PREFIX.libxml2}',g" \
			-e "/^\"/s,/usr/include,${BUILDLINK_PREFIX.iconv}/include,g" \
			-e "/^\"/s,/usr/local/include,${BUILDLINK_PREFIX.iconv}/include,g"

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=${PKGVERSION}
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
