# $NetBSD: Makefile,v 1.4 2009/08/26 19:56:56 sno Exp $
#

DISTNAME=	libunique-1.0.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libunique/1.0/}

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibUnique
COMMENT=	Library for writing single instance applications

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE+=	unique.pc.in

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
