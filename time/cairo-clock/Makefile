# $NetBSD: Makefile,v 1.25 2012/09/07 19:17:36 adam Exp $
#

DISTNAME=	cairo-clock_0.3.3-1
PKGNAME=	cairo-clock-0.3.3
PKGREVISION=	18
CATEGORIES=	time
MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://macslow.thepimp.net/?page_id=23
COMMENT=	Analog clock drawn with vector-graphics

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cairo-clock-0.3.3
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config msgfmt

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
