# $NetBSD: Makefile,v 1.4 1999/03/04 08:56:06 tron Exp $

DISTNAME=	gtkglarea-1.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.student.oulu.fi/~jlof/gtkglarea/

DEPENDS+=       Mesa-3.0:../../graphics/Mesa
DEPENDS+=       gtk+-1.2.0:../../x11/gtk

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
