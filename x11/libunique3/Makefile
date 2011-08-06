# $NetBSD: Makefile,v 1.3 2011/08/06 22:21:58 ryoon Exp $
#

DISTNAME=	libunique-3.0.2
PKGNAME=	${DISTNAME:S/libunique/libunique3/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libunique/3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibUnique
COMMENT=	Library for writing single instance applications
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	unique.pc.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
