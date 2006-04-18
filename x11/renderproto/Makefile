# $NetBSD: Makefile,v 1.1.1.1 2006/04/18 17:16:06 reed Exp $
#

DISTNAME=		renderproto-0.9.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Render extension headers from modular X.org

CONFLICTS+=		renderext-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/renderproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
