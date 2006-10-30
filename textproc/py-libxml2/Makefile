# $NetBSD: Makefile,v 1.25 2006/10/30 20:59:10 drochner Exp $

DISTNAME=	libxml2-2.6.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxml2/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.6/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2

WRKSRC=		${WRKDIR}/${DISTNAME}/python
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
NO_CONFIGURE=	YES

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "/ROOT/s,'/usr','${BUILDLINK_PREFIX.libxml2}',g" \
			-e "/^\"/s,/usr/include,${BUILDLINK_PREFIX.iconv}/include,g" \
			-e "/^\"/s,/usr/local/include,${BUILDLINK_PREFIX.iconv}/include,g"

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=${PKGVERSION}
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
