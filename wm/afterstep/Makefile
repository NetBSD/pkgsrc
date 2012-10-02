# $NetBSD: Makefile,v 1.58 2012/10/02 17:12:05 tron Exp $

DISTNAME=	AfterStep-2.1.2
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
PKGREVISION=	21
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/v2.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bash:run gmake perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-send-postcard-to-developer
REPLACE_PERL+=		tools/ascommand.pl tools/installastheme.pl.in tools/makeastheme.pl.in
REPLACE_BASH+=		tools/importasmenu

INSTALLATION_DIRS+=	share/gnome/wm-properties

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
