# $NetBSD: Makefile,v 1.34 2021/07/13 08:16:17 nia Exp $
#

DISTNAME=	amiwm0.21pl2
PKGNAME=	amiwm-0.21pl2
CATEGORIES=	wm x11
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lysator.liu.se/~marcus/amiwm.html
COMMENT=	X window manager with Amiga look and feel
LICENSE=	amiwm-license

RESTRICTED=		Distribution limited to non-commercial purposes, unmodified source only.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	ksh:run yacc lex
REPLACE_KSH=	Xsession.in Xsession2.in

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
