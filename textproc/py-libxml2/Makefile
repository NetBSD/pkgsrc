# $NetBSD: Makefile,v 1.5 2004/02/12 16:19:58 minskim Exp $

DISTNAME=	libxml2-2.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Python wrapper for libxml2

WRKSRC=		${WRKDIR}/${DISTNAME}/python
PYDISTUTILSPKG=	YES
USE_BUILDLINK3=	YES
NO_CONFIGURE=	YES

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	"Fixing hardcoded paths."
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,'/usr','${BUILDLINK_PREFIX.libxml2}',g"

BUILDLINK_DEPENDS.libxml2+=	libxml2>=${PKGVERSION}
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
