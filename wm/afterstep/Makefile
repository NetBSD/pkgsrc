# $NetBSD: Makefile,v 1.31 2005/07/28 10:25:14 adam Exp $

DISTNAME=	AfterStep-2.1.2
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
