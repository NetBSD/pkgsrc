# $NetBSD: Makefile,v 1.10 2000/01/02 18:02:42 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/12 16:50:43 vanilla Exp
#

DISTNAME=	Gtk---1.0.3
PKGNAME=	gtk---1.0.3
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lazy.ton.tut.fi/gtk--/gtk--.html

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
BUILD_DEPENDS+=	gm4:../../devel/m4

USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
	  ${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../mk/bsd.pkg.mk"
