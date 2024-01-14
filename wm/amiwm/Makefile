# $NetBSD: Makefile,v 1.37 2024/01/14 15:56:01 rillig Exp $

DISTNAME=	amiwm0.22pl2
PKGNAME=	amiwm-0.22pl2
PKGREVISION=	1
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

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-install
SUBST_FILES.destdir=	${DESTDIR}${PREFIX}/lib/amiwm/Xinitrc \
			${DESTDIR}${PREFIX}/lib/amiwm/Xsession \
			${DESTDIR}${PREFIX}/lib/amiwm/Xsession2
SUBST_SED.destdir=	-e 's|${DESTDIR}${PREFIX}|${PREFIX}|g'

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
