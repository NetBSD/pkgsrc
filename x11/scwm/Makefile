# $NetBSD: Makefile,v 1.5 1999/10/23 00:05:18 tron Exp $
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scwm.mit.edu/

DEPENDS+=	guile-1.3.2:../../lang/guile
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gtar-1.12:../../archivers/gtar
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}	\
			--with-gtk-prefix=${X11BASE}		\
			--enable-multibyte

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
