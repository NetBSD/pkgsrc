# $NetBSD: Makefile,v 1.4 2001/05/04 02:39:12 fredb Exp $
#

DISTNAME=	chimera-2.0a19
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	fredb@netbsd.org
#HOMEPAGE=	http://www.cs.unlv.edu/chimera/
COMMENT=	World Wide Web Browser for X Windows

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>1.0.9:../../graphics/png

USE_IMAKE=	yes

pre-configure:
	cd ${WRKSRC} && ${SED}					\
	    -e 's|@@LOCALBASE@@|${LOCALBASE}|'			\
	    -e 's|@@PREFIX@@|${PREFIX}|'			\
	    -e 's|@@X11BASE@@|${X11BASE}|'			\
	    < Common.tmpl.dist > Common.tmpl

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/chimera
	cd ${WRKSRC}/doc && ${INSTALL_DATA}			\
	    HINTS INFO LICENSE ${X11PREFIX}/share/doc/chimera

.include "../../mk/bsd.pkg.mk"
