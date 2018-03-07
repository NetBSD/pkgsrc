# $NetBSD: Makefile,v 1.8 2018/03/07 11:57:39 wiz Exp $

DISTNAME=		printproto-1.0.5
PKGREVISION=		1
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Print extension headers from X.org

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	printproto.pc.in

CONFIGURE_ENV+=		MISC_MAN_SUFFIX=7

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
