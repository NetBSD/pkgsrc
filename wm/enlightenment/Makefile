# $NetBSD: Makefile,v 1.21 2004/03/10 14:12:51 xtraeme Exp $
#

DISTNAME=		enlightenment-0.16.6
PKGREVISION=		1
CATEGORIES=		x11 gnome wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Highly themeable and configurable window manager

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-fsstd
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

REPLACE_PERL=		scripts/*.pl scripts/e_gen_menu

post-install:
	for FILE in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
		${TOUCH} ${PREFIX}/$${FILE}; \
	done
	${FIND} ${PREFIX}/share/enlightenment/themes -type d -print | \
	${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/enlightenment/themes -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/fnlib/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
