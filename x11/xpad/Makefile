# $NetBSD: Makefile,v 1.33 2011/01/13 13:40:08 wiz Exp $
#

DISTNAME=	xpad-1.12
PKGREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpad/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xpad.sourceforge.net/
COMMENT=	Sticky notes application in GTK 2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

LIBS.SunOS+=		-lX11

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
