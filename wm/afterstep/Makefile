# $NetBSD: Makefile,v 1.28 2005/05/22 20:08:43 jlam Exp $
#

DISTNAME=	AfterStep-2.00.01
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_PERL5=		run
USE_X11=		YES

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
