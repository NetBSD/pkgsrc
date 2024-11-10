# $NetBSD: Makefile,v 1.34 2024/11/10 08:27:46 wiz Exp $

DISTNAME=		xtrans-1.5.2
CATEGORIES=		x11 net
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
