# $NetBSD: Makefile,v 1.1.1.1 2009/11/08 18:26:15 jakllsch Exp $
#

DISTNAME=	libxdg-basedir-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://n.ethz.ch/student/nevillm/download/libxdg-basedir/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://n.ethz.ch/student/nevillm/download/libxdg-basedir/
COMMENT=	XDG Base Directory library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pkgconfig/libxdg-basedir.pc.in

.include "../../mk/bsd.pkg.mk"
