# $NetBSD: Makefile,v 1.31 2003/11/30 22:58:40 jschauma Exp $

DISTNAME=		gtkglarea-1.2.2
PKGREVISION=		4
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.student.oulu.fi/~jlof/gtkglarea/
COMMENT=		OpenGL/Mesa widget for GTK+ GUI toolkit

USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--with-GL-prefix="${BUILDLINK_PREFIX.MesaLib}"
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

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
