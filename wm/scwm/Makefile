# $NetBSD: Makefile,v 1.4 2001/03/29 12:05:04 wennmach Exp $
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scwm.sourceforge.net/
COMMENT=	Window manager with a powerful configuration (Guile Scheme) language

DEPENDS+=	guile>=1.3.2:../../lang/guile
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gtar-1.12:../../archivers/gtar
DEPENDS+=	readline>=4.0:../../devel/readline

BROKEN=		Current release does not work with guile-1.4.0.

INFO_FILES=	scwm.info

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
