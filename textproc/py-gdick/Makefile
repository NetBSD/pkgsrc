# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:20 tv Exp $

DISTNAME=	gdick-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gdick/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gdick.sourceforge.net/
COMMENT=	English-Korean Dictionary Client for GNOME2

DEPENDS+=	${PYPKGPREFIX}-cjkcodecs-[0-9]*:../../converters/py-cjkcodecs

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	GNOME_GDick.server lib/gdick/gdick.py
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
