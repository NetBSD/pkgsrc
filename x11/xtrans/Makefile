# $NetBSD: Makefile,v 1.32 2023/06/03 06:20:21 wiz Exp $

DISTNAME=		xtrans-1.5.0
CATEGORIES=		x11 net
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
