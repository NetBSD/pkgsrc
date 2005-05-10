# $NetBSD: Makefile,v 1.1.1.1 2005/05/10 20:27:54 jmmv Exp $
#

DISTNAME=	clearlooks-metacity-0.5.2a
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clearlooks/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://clearlooks.sourceforge.net/
COMMENT=	New and modern-looking GTK2+ engine, based on Bluecurve (Metacity theme)

NO_BUILD=	yes
NO_BUILDLINK=	yes
USE_DIRS+=	theme-1.1
USE_LANGUAGES=	# empty
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/Clearlooks/metacity-1
	${INSTALL_DATA} ${WRKSRC}/Clearlooks/metacity-1/metacity-theme-1.xml \
		${PREFIX}/share/themes/Clearlooks/metacity-1/

.include "../../mk/bsd.pkg.mk"
