# $NetBSD: Makefile,v 1.27 2019/03/17 08:22:19 wiz Exp $

DISTNAME=		xtrans-1.4.0
CATEGORIES=		x11 net
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
