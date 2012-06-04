# $NetBSD: Makefile,v 1.14 2012/06/04 09:10:04 wiz Exp $
#

DISTNAME=		inputproto-2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Input extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	inputproto.pc.in
CONFIGURE_ARGS+=	--with-asciidoc=no

.include "../../mk/bsd.pkg.mk"
