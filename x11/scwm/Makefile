# $NetBSD: Makefile,v 1.18 2000/08/23 23:14:35 tron Exp $
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scwm.mit.edu/

DEPENDS+=	guile>=1.3.2:../../lang/guile
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gtar-1.12:../../archivers/gtar
DEPENDS+=	readline>=4.0:../../devel/readline

BROKEN=		Current release does not work with guile-1.4.0.

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}	\
			--with-gtk-prefix="${GTKDIR}"		\
			--enable-multibyte

USE_X11BASE=	YES
USE_XPM=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.pkg.mk"
