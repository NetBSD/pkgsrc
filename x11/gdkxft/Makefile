# $NetBSD: Makefile,v 1.22 2004/04/27 09:28:30 recht Exp $
#

DISTNAME=		gdkxft-1.5
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdkxft/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gdkxft.sourceforge.net/
COMMENT=		Transparently add anti-aliased font support to gtk+ applications

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXft.a)
PKG_FAIL_REASON=	"${PKGNAME} requires XFree86-4.0 or higher"
.endif

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdkxft
.for doc in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/gdkxft
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/controlcenter/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
