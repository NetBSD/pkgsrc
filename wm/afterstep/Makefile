# $NetBSD: Makefile,v 1.38 2007/02/01 21:51:55 joerg Exp $

DISTNAME=	AfterStep-2.1.2
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-send-postcard-to-developer
REPLACE_PERL+=		tools/ascommand.pl tools/installastheme.pl tools/makeastheme.pl

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
