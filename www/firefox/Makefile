# $NetBSD: Makefile,v 1.9 2004/07/03 04:00:12 taya Exp $

MOZILLA=	firefox
MOZILLA_BIN=	firefox-bin
MOZCONFDIR=	.mozilla
MOZ_VER=	0.9.1
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	${MOZILLA}-${MOZ_VER}-source
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		http://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/ \
		ftp://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer
CONFIGURE_ARGS+=	--enable-extensions=default,-irc

BUILD_MATHML=	# defined

pre-install:
	${CP} -r ${WRKSRC}/dist/bin/defaults/profile/extensions \
							${WRKSRC}/dist/bin
	${MV} ${WRKSRC}/dist/bin/extensions/installed-extensions.txt \
		${WRKSRC}/dist/bin/extensions/installed-extensions-processed.txt

.include "../../www/mozilla/Makefile.common"
