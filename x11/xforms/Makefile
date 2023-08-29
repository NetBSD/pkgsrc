# $NetBSD: Makefile,v 1.73 2023/08/29 15:05:39 vins Exp $
#

DISTNAME=	xforms-2c1a9f151baf50887a517280645ec23379fb96f8
PKGNAME=	xforms-1.2.5pre2
CATEGORIES=	x11
MASTER_SITES=	https://git.savannah.nongnu.org/cgit/xforms.git/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoreconf automake

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
