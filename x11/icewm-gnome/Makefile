# $NetBSD: Makefile,v 1.1.1.1 2000/01/23 16:03:36 tron Exp $

DISTNAME=	icewm-1.0.1
PKGNAME=	icewm-gnome-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://download.sourceforge.net/icewm/ \
		ftp://ftp.fu-berlin.de/unix/X11/window-managers/icewm/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://icewm.sourceforge.net/

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=	icewm-[0-9]*

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ARGS+= --with-gnome-menus=${X11BASE}/bin/gnome-config
CONFIGURE_ENV+=	LIBS="-lintl"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icewm
.for f in BUGS CHANGES COPYING FAQ README TODO doc/icewm.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/icewm
.endfor
.for f in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	${INSTALL_DATA} ${WRKSRC}/doc/icewm-${f}.html ${PREFIX}/share/doc/icewm
.endfor

.include "../../mk/bsd.pkg.mk"
