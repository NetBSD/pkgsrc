# $NetBSD: Makefile,v 1.19 2000/07/15 20:39:26 agc Exp $

DISTNAME=		gtkglarea-1.2.1
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.student.oulu.fi/~jlof/gtkglarea/

DEPENDS+=		Mesa-*:../../graphics/Mesa
DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-GL-prefix=${X11BASE}
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
