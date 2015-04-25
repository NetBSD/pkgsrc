# $NetBSD: Makefile,v 1.47 2015/04/25 14:25:06 tnn Exp $

DISTNAME=	gtkglarea-1.2.3
PKGREVISION=	4
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20011204180640/http://www.student.oulu.fi/~jlof/gtkglarea/
COMMENT=	OpenGL/Mesa widget for GTK+ GUI toolkit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-MesaGL

post-install:
	${INSTALL_MAN_DIR} "${DESTDIR}${PREFIX}/share/doc/gtkglarea"
	set -e; cd ${WRKSRC}/docs ; \
	${INSTALL_MAN} HOWTO.txt "${DESTDIR}${PREFIX}/share/doc/gtkglarea" ; \
	${INSTALL_MAN} gdkgl.txt "${DESTDIR}${PREFIX}/share/doc/gtkglarea" ; \
	${INSTALL_MAN} gtkglarea.txt "${DESTDIR}${PREFIX}/share/doc/gtkglarea"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
