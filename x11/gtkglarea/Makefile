# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:56 agc Exp $

DISTNAME=	gtkglarea-1.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.student.oulu.fi/~jlof/gtkglarea/

DEPENDS+=       Mesa-3.0:../../graphics/Mesa
DEPENDS+=       gtk+-1.1.12:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
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
