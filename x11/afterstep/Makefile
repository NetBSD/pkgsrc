# $NetBSD: Makefile,v 1.9 1999/03/04 14:59:24 tron Exp $

DISTNAME=		AfterStep-1.6.0
PKGNAME=		afterstep-1.6.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/stable/ \
			ftp://ftp.digex.net/pub/os/wm/AfterStep/stable/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		rplay-3.2.0b6:../../audio/rplay
DEPENDS+=		asclock-11:../../x11/asclock

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-png-includes=${LOCALBASE}/include \
			--with-png-lib=${LOCALBASE}/lib \
			--with-jpeg-includes=${LOCALBASE}/include \
			--with-jpeg-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

post-patch:
	for i in ` find ${WRKSRC} -name "*.man" -print `; do \
	  ${CP} $$i $$i.orig ;\
	  ${SED} -e 's@/usr/local/@${PREFIX}/@g' < $$i.orig > $$i ; \
	done

.include "../../mk/bsd.pkg.mk"
