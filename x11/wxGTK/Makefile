# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 00:19:08 tsarna Exp $
#

DISTNAME=	wxGTK-2.2.0
CATEGORIES=	x11
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~wxxt/

DEPENDS+=       gtk+>=1.2.7:../../x11/gtk
DEPENDS+=       jpeg-6b:../../graphics/jpeg
DEPENDS+=       png>=1.0.3:../../graphics/png
DEPENDS+=       tiff>=3.5.2:../../graphics/tiff

WRKSRC=		${WRKDIR}/wxGTK

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk --disable-threads

.include "../../mk/bsd.pkg.mk"
