# $NetBSD: Makefile,v 1.7 2000/07/11 10:39:05 agc Exp $

DISTNAME=	xfce-3.3.1
CATEGORIES=	x11
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.xfce.org/

DEPENDS+=       gettext-0.10.*:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-1.9.*:../../graphics/imlib
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XFCE_LOCALE_DIR=${PREFIX}/share/locale
CONFIGURE_ARGS+=--without-included-gettext \
		--datadir=${PREFIX}/share \
		--with-imlib=`${PKG_INFO} -qp imlib | ${AWK} '{print $$2}'` \
		--with-xpm=`${PKG_INFO} -qp xpm | ${AWK} '{print $$2}'`
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
