# $NetBSD: Makefile,v 1.17 2014/05/30 12:52:39 wiz Exp $

DISTNAME=		inputproto-2.3.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Input extension headers from X.org

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	inputproto.pc.in
CONFIGURE_ARGS+=	--with-asciidoc=no

.include "../../mk/bsd.pkg.mk"
