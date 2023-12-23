# $NetBSD: Makefile,v 1.21 2023/12/23 09:39:08 zafer Exp $

DISTNAME=	xscribble
PKGNAME=	xscribble-20000616
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	#
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.handhelds.org/projects/xscribble.html
COMMENT=	Handwriting recognition (like graffiti)

MAKE_JOBS_SAFE=		no

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SYS_LIBRARIES=	-lmx
MAKE_ENV+=	SYS_LIBRARIES=${SYS_LIBRARIES:Q}
.endif

INSTALLATION_DIRS=	share/examples/xscribble

post-install:
	${INSTALL_DATA} ${WRKSRC}/classifiers/*.cl ${DESTDIR}${PREFIX}/share/examples/xscribble

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
