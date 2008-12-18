# $NetBSD: Makefile,v 1.1.1.1 2008/12/18 00:32:14 ahoka Exp $
#

DISTNAME=	unique-1.0.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.gnome.org/~ebassi/source/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibUnique
COMMENT=	Library for writing single instance applications

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	unique.pc.in

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
