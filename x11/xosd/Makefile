# $NetBSD: Makefile,v 1.1.1.1 2003/04/07 14:46:28 jmmv Exp $
#

DISTNAME=	xosd-2.1.3
CATEGORIES=	x11
MASTER_SITES=	http://www.ignavus.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ignavus.net/software.html
COMMENT=	Library to display shaped text on your X display

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
#USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/libtool-disable-static

.include "../../audio/xmms/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
