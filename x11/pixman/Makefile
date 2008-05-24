# $NetBSD: Makefile,v 1.11 2008/05/24 21:45:20 tnn Exp $
#

DISTNAME=	pixman-0.10.0
PKGNAME=	${DISTNAME:C/pl[0-9]*//}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in

WRKSRC=	 	${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
