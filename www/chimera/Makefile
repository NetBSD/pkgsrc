# $NetBSD: Makefile,v 1.1.1.1 2000/10/19 14:23:00 fredb Exp $
#

DISTNAME=	chimera-2.0a19
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.cs.unlv.edu/chimera/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.8:../../graphics/png

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
