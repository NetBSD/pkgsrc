# $NetBSD: Makefile,v 1.22 2000/07/27 08:18:19 jlam Exp $

DISTNAME=		enlightenment-0.16.2
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		esound>=0.2.18:../../audio/esound
DEPENDS+=		imlib>=1.9.8:../../graphics/imlib
DEPENDS+=		fnlib-0.5:../../graphics/fnlib
DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		libghttp-*:../../www/libghttp

USE_PERL5=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fsstd
CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${LOCALBASE}/include/freetype
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

post-install:
	for file in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
		${TOUCH} ${PREFIX}/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
