# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:28 tv Exp $
#

DISTNAME=		XaoS-3.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		YES
USE_GNU_TOOLS=		make
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no
# DGA fails to link somehow, XXX should be fixed
CONFIGURE_ARGS+=	--with-dga-driver=no
INFO_FILES=		xaos.info

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e 's,/usr/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
