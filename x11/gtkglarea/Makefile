# $NetBSD: Makefile,v 1.23 2001/04/07 19:34:31 rh Exp $

DISTNAME=		gtkglarea-1.2.2
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.student.oulu.fi/~jlof/gtkglarea/
COMMENT=		OpenGL/Mesa widget for GTK+ GUI toolkit

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11BASE=		YES
USE_MESA=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
EVAL_PREFIX+=		GTKDIR=gtk+ MESADIR=Mesa
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-GL-prefix=${MESADIR}
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

.include "../../mk/bsd.pkg.mk"
