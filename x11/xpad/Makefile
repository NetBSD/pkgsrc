# $NetBSD: Makefile,v 1.8 2004/03/08 19:40:46 jmmv Exp $
#

DISTNAME=	xpad-1.12
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpad/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xpad.sourceforge.net/
COMMENT=	Sticky notes application in GTK 2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

LIBS.SunOS=		-lX11

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
