# $NetBSD: Makefile,v 1.2 2010/12/02 15:33:16 wiz Exp $
#

DISTNAME=	libxdg-basedir-1.1.1
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
