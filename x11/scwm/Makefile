# $NetBSD: Makefile,v 1.10 2000/07/10 10:40:43 agc Exp $
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scwm.mit.edu/

DEPENDS+=	guile-1.3.*:../../lang/guile
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gtar-1.12:../../archivers/gtar
DEPENDS+=	readline-4.0:../../devel/readline
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}	\
			--with-gtk-prefix="`${PKG_INFO} -qp gtk+ | ${AWK} '{print $$2}'`" \
			--enable-multibyte

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
