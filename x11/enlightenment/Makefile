# $NetBSD: Makefile,v 1.18 2000/03/05 22:37:58 soren Exp $

DISTNAME=		enlightenment-0.16.2
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		esound-*:../../audio/esound
DEPENDS+=		imlib>=1.9.8:../../graphics/imlib
DEPENDS+=		fnlib-0.5:../../graphics/fnlib
DEPENDS+=		freetype-*:../../graphics/freetype
DEPENDS+=		libghttp-*:../../www/libghttp

USE_PERL5=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fsstd
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

post-install:
	for file in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
		${TOUCH} ${PREFIX}/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
