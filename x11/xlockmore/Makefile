# $NetBSD: Makefile,v 1.29 2000/05/11 16:37:52 hubertf Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.16.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tux.org/~bagleyd/xlockmore.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-*:../../graphics/Mesa

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk

post-patch:
		for i in xlock/sound.c xlock/resource.c ; do \
			f=${WRKSRC}/$$i ; \
			[ -f $$f.BAK ] || mv $$f $$f.BAK ; \
			sed \
				-e 's|@PREFIX@|${PREFIX}|g' \
				<$$f.BAK >$$f ; \
		done

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/xlockmore
		${INSTALL_DATA}	\
			${WRKSRC}/sounds/thank-you.au	\
			${WRKSRC}/sounds/identify-please.au	\
			${WRKSRC}/sounds/not-programmed.au	\
			${WRKSRC}/sounds/complete.au	\
				${PREFIX}/lib/X11/xlockmore

.include "../../mk/bsd.pkg.mk"
