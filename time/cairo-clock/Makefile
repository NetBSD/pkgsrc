# $NetBSD: Makefile,v 1.45 2018/11/14 22:22:31 kleink Exp $

DISTNAME=	cairo-clock_0.3.3-1
PKGNAME=	cairo-clock-0.3.3
PKGREVISION=	36
CATEGORIES=	time
#MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://macslow.thepimp.net/?page_id=23
COMMENT=	Analog clock drawn with vector-graphics

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
