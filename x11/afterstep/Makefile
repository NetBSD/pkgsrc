# $NetBSD: Makefile,v 1.12 1999/10/28 10:07:42 agc Exp $

DISTNAME=	AfterStep-1.6.10
PKGNAME=	afterstep-1.6.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.afterstep.org/pub/stable/ \
		ftp://ftp.digex.net/pub/X11/window-managers/afterstep/AfterStep/pub/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.afterstep.org/

DEPENDS+=	asclock-1.0:../../x11/asclock
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	rplay-3.2.0b6:../../audio/rplay
DEPENDS+=	xli-1.16:../../graphics/xli
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-png-includes=${LOCALBASE}/include \
			--with-png-lib=${LOCALBASE}/lib \
			--with-jpeg-includes=${LOCALBASE}/include \
			--with-jpeg-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

post-patch:
	for i in ` find ${WRKSRC} -name "*.man" -print `; do \
	  ${MV} $$i $$i.orig ;\
	  ${SED} -e 's@/usr/local/@${PREFIX}/@g' < $$i.orig > $$i ; \
	  ${RM} $$i.orig ;\
	done

.include "../../mk/bsd.pkg.mk"
