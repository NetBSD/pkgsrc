# $NetBSD: Makefile,v 1.9 2004/07/14 21:06:57 ben Exp $
#

DISTNAME=		XaoS-3.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		YES
USE_GNU_TOOLS=		make
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no
# DGA fails to link somehow, XXX should be fixed
CONFIGURE_ARGS+=	--with-dga-driver=no
INFO_FILES=		xaos.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
