# $NetBSD: Makefile,v 1.9 1999/08/28 09:43:15 rh Exp $

DISTNAME=	gtkglarea-1.2.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.student.oulu.fi/~jlof/gtkglarea/

DEPENDS+=       Mesa-3.0:../../graphics/Mesa
DEPENDS+=       gtk+-1.2.4:../../x11/gtk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
CONFIGURE_ARGS+= --with-gtk-prefix=${X11BASE}
CONFIGURE_ARGS+= --with-GL-prefix=${X11BASE}
CONFIGURE_ARGS+= --with-lib-MesaGL

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/gtkglarea
	cd ${WRKSRC}/docs ; \
	${INSTALL_MAN} HOWTO.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gdkgl.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gtkglarea.txt ${PREFIX}/share/doc/gtkglarea
	
.include "../../mk/bsd.pkg.mk"
