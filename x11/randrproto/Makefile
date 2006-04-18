# $NetBSD: Makefile,v 1.2 2006/04/18 17:27:30 reed Exp $
#

DISTNAME=		randrproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Randr extension headers from modular X.org

CONFLICTS+=		randrext-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/randrproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
