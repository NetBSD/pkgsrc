# $NetBSD: Makefile,v 1.12 2000/08/23 23:14:35 tron Exp $

DISTNAME=	xfce-3.3.1
CATEGORIES=	x11
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.xfce.org/

DEPENDS+=       gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-1.9.*:../../graphics/imlib

USE_X11=	YES
USE_XPM=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	XFCE_LOCALE_DIR=${PREFIX}/share/locale

EVAL_PREFIX+=	IMLIBDIR=imlib XPMDIR=xpm
CONFIGURE_ARGS+=--without-included-gettext \
		--datadir=${PREFIX}/share \
		--with-imlib=${IMLIBDIR} \
		--with-xpm=${XPMDIR}
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
