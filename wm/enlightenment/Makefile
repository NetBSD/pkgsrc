# $NetBSD: Makefile,v 1.9.2.1 2002/07/01 17:45:12 jlam Exp $

DISTNAME=		enlightenment-0.16.4
PKGREVISION=		1
CATEGORIES=		x11 gnome wm
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Window manager for X

USE_BUILDLINK2=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fsstd
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

post-install:
	for FILE in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
	  ${TOUCH} ${PREFIX}/$${FILE}; \
	done
	${FIND} ${PREFIX}/share/enlightenment/themes -type d | \
	${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/enlightenment/themes -type f | \
	${XARGS} ${CHMOD} ${NONBINMODE}

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/fnlib/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
