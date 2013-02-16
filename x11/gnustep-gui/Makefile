# $NetBSD: Makefile,v 1.55 2013/02/16 11:25:02 wiz Exp $

DISTNAME=	gnustep-gui-0.22.0
PKGREVISION=	2
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

INSTALLATION_DIRS+=	share/GNUstep/Applications

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
