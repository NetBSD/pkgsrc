# $NetBSD: Makefile,v 1.6 2001/01/15 18:11:51 drochner Exp $
#

DISTNAME=	Xbae-4.8.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.lesstif.org/Xbae.html

USE_MOTIF=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--disable-build-12 \
			--enable-build-20 --enable-default-20
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/ac_find_xbae.m4 \
		${LOCALBASE}/share/aclocal/ac_find_xbae.m4

.include "../../mk/bsd.pkg.mk"
