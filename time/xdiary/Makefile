# $NetBSD: Makefile,v 1.1 2023/01/22 20:08:17 vins Exp $

DISTNAME=	xmdiary-3.0.3
PKGNAME=	${DISTNAME:S/m//}
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.ibiblio.org/pub/X11/contrib/office/xmdiary-README
COMMENT=	Calendar utility based on Motif/X
LICENSE=	0-clause-bsd

MKPIE_SUPPORTED=	no

USE_IMAKE=	yes

SUBST_CLASSES+=		cc
SUBST_STAGE.cc=		pre-configure
SUBST_FILES.cc=		XDiary.tmpl
SUBST_VARS.cc=		CC
SUBST_MESSAGE.cc=	Defining preferred compiler.

SUBST_CLASSES+=		malloc
SUBST_STAGE.malloc=	pre-configure
SUBST_FILES.malloc=	tools/LstLinked.c tools/System.c \
			xtools/xitClipboard.c xtools/xitInfoFile.c
SUBST_MESSAGE.malloc=	Replacing malloc.h
SUBST_SED.malloc=	-e 's|<malloc.h>|<stdlib.h>|g'

MAKE_FLAGS+=	INSTALL=${INSTALL:Q}
MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

MAKE_FLAGS+=	XDEXEDIR=${PREFIX}/bin
MAKE_FLAGS+=	XDMANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	XDDATADIR=${PREIFX}/lib/${PKGBASE}
MAKE_FLAGS+=	XDAPPDIR=${PREFIX}/lib/X11/app-defaults

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-install:
	${RUN}${PRINTF} '%s\n' \
	'XDiary requires the XAPPLRESDIR environmental variable to be set to:'	\
	'${PREFIX}/lib/X11/app-defaults' > 					\
		${DESTDIR}${PREFIX}/share/doc/xdiary/README.pkgsrc

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
