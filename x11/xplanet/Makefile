# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:40 tv Exp $

DISTNAME=	xplanet-1.1.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	http://xplanet.sourceforge.net/
COMMENT=	Rotating rendered map of the Earth in X11 root window

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

# directory creation should be fixed in the future release of xplanet
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xplanet
.for dir in arcs config fonts images markers origin satellites \
		scripts spice stars
	${INSTALL_DATA_DIR} ${PREFIX}/share/xplanet/${dir}
.endfor

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
