# $NetBSD: Makefile,v 1.3 2003/04/12 09:21:24 jmmv Exp $
#

DISTNAME=	xosd-2.2.0
CATEGORIES=	x11
MASTER_SITES=	http://www.ignavus.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ignavus.net/software.html
COMMENT=	Library to display shaped text on your X display

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/libtool-disable-static

.include "../../audio/xmms/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
