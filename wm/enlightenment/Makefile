# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:47 wiz Exp $

DISTNAME=		enlightenment-0.16.4
CATEGORIES=		x11 gnome wm
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
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

post-install:
	for FILE in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
	  ${TOUCH} ${PREFIX}/$${FILE}; \
	done
	${FIND} ${PREFIX}/share/enlightenment/themes -type d | \
	xargs ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/enlightenment/themes -type f | \
	xargs ${CHMOD} ${NONBINMODE}

.include "../../mk/bsd.pkg.mk"
