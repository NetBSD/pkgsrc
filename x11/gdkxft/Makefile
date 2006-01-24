# $NetBSD: Makefile,v 1.30 2006/01/24 07:32:51 wiz Exp $
#

DISTNAME=		gdkxft-1.5
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdkxft/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gdkxft.sourceforge.net/
COMMENT=		Transparently add anti-aliased font support to gtk+ applications

.include "../../mk/bsd.prefs.mk"

USE_DIRS+=		xdg-1.1
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static

CPPFLAGS+=		-I${LOCALBASE}/include/libcapplet1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdkxft
.for doc in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/gdkxft
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
