# $NetBSD: Makefile,v 1.6 1999/04/26 19:30:23 garbled Exp $
#

DISTNAME=       XmHTML-1.1.5
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/

DEPENDS +=	xpm-3.4k:../../graphics/xpm
DEPENDS +=	jpeg-6b:../../graphics/jpeg
DEPENDS +=	lesstif-0.87.1:../lesstif
DEPENDS +=      png-1.0.3:../../graphics/png

USE_X11=	yes

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${XMKMF})

.include "../../mk/bsd.pkg.mk"
