# $NetBSD: Makefile,v 1.12 2003/07/17 22:55:31 grant Exp $
#

DISTNAME=	chimera-2.0a19
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.chimera.org/
COMMENT=	World Wide Web Browser for X Windows

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

pre-configure:
	cd ${WRKSRC} && ${SED}					\
	    -e 's|@@LOCALBASE@@|${LOCALBASE}|'			\
	    -e 's|@@PREFIX@@|${PREFIX}|'			\
	    -e 's|@@X11BASE@@|${X11BASE}|'			\
	    Common.tmpl.dist > Common.tmpl

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/chimera
	cd ${WRKSRC}/doc && ${INSTALL_DATA}			\
	    HINTS INFO LICENSE ${X11PREFIX}/share/doc/chimera

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
