# $NetBSD: Makefile,v 1.38 2005/10/23 19:06:32 wiz Exp $

DISTNAME=	gtkglarea-1.2.3
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openev/} \
		http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.student.oulu.fi/~jlof/gtkglarea/
COMMENT=	OpenGL/Mesa widget for GTK+ GUI toolkit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-MesaGL

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/gtkglarea
	cd ${WRKSRC}/docs ; \
	${INSTALL_MAN} HOWTO.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gdkgl.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gtkglarea.txt ${PREFIX}/share/doc/gtkglarea

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
