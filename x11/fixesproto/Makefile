# $NetBSD: Makefile,v 1.2 2006/07/11 12:51:34 abs Exp $
#

DISTNAME=		fixesproto-3.0.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fixes extension headers from X.org

CONFLICTS+=		fixesext-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fixesproto.pc.in
USE_LANGUAGES=		# empty

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
