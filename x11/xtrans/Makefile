# $NetBSD: Makefile,v 1.29 2021/12/01 13:01:17 nia Exp $

DISTNAME=		xtrans-1.4.0
CATEGORIES=		x11 net
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

X11_BUILTIN_NAME=	xtrans
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
