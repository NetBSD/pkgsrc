# $NetBSD: Makefile,v 1.29 2013/11/09 06:10:48 dholland Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20p48
PKGREVISION=	3
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~marcus/amiwm.html
COMMENT=	X window manager with Amiga look and feel
LICENSE=	amiwm-license

RESTRICTED=	Distribution limited to non-commercial purposes, unmodified binaries only.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# Extensive use of 32-bit values to hold pointers
NOT_FOR_PLATFORM+=	${LP64PLATFORMS}

USE_TOOLS+=	ksh:run yacc lex
REPLACE_KSH=	Xsession.in Xsession2.in

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_X11_EXTENSIONS_SHAPE_H=1
CFLAGS+=	-O
CONFIGURE_ENV+=	CFLAGS=${CFLAGS:M*:Q}
CONFIGURE_ENV+=	X_PRE_LIBS=${X_PRE_LIBS:Q}
CONFIGURE_ENV+=	X_EXTRA_LIBS=-lXt

X_PRE_LIBS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib

INSTALLATION_DIRS=	bin

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
