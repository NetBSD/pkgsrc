# $NetBSD: Makefile,v 1.16 2003/11/12 01:31:52 salo Exp $
#

DISTNAME=		gdkxft-1.5
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdkxft/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gdkxft.sourceforge.net/
COMMENT=		Transparently add anti-aliased font support to gtk+ applications

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXft.a)
PKG_FAIL_REASON=	"${PKGNAME} requires XFree86-4.0 or higher"
.endif

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdkxft
.for doc in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/gdkxft
.endfor

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
