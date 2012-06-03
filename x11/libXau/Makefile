# $NetBSD: Makefile,v 1.9 2012/06/03 17:25:09 wiz Exp $
#

DISTNAME=		libXau-1.0.7
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Authorization Protocol for X from X.org
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

PKGCONFIG_OVERRIDE+=	xau.pc.in

CPPFLAGS.OSF1+=		-pthread # Required by compiler if including pthread.h

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
