# $NetBSD: Makefile,v 1.3 2004/01/23 21:50:49 jmmv Exp $

DISTNAME=	libxml2-2.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2

WRKSRC=		${WRKDIR}/${DISTNAME}/python
PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES
NO_CONFIGURE=	YES

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	"Fixing hardcoded paths."
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,'/usr','${BUILDLINK_PREFIX.libxml2}',g"

BUILDLINK_DEPENDS.libxml2=	libxml2>=${PKGVERSION}
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
