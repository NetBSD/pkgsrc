# $NetBSD: Makefile,v 1.9 1999/11/07 17:25:31 hubertf Exp $
#

DISTNAME=       XmHTML-1.1.5
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png

USE_X11=	yes
USE_MOTIF=	yes

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${XMKMF})

.include "../../mk/bsd.pkg.mk"
