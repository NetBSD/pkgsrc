# $NetBSD: Makefile,v 1.34 2004/10/03 00:18:33 tv Exp $

DISTNAME=		gtkglarea-1.2.2
PKGREVISION=		5
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.student.oulu.fi/~jlof/gtkglarea/
COMMENT=		OpenGL/Mesa widget for GTK+ GUI toolkit

USE_X11BASE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-lib-MesaGL

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/gtkglarea
	cd ${WRKSRC}/docs ; \
	${INSTALL_MAN} HOWTO.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gdkgl.txt ${PREFIX}/share/doc/gtkglarea ; \
	${INSTALL_MAN} gtkglarea.txt ${PREFIX}/share/doc/gtkglarea
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtkgl.m4 \
		${LOCALBASE}/share/aclocal/gtkgl.m4

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
