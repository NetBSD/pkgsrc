# $NetBSD: Makefile,v 1.1.1.1 2002/11/20 21:39:37 jschauma Exp $
#

DISTNAME=		whiteBOX-0.4.2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=whitebox/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://whitebox.sourceforge.net/
COMMENT=		Multi-purpose configuration tool for Blackbox

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes

# this prevents us from build-depending on autoconf and automake
# is it worth it?
pre-install:
	${RM} -f ${WRKSRC}/mkinstalldirs
	${ECHO} "#!${SH}" > ${WRKSRC}/mkinstalldirs
	${ECHO} "${ECHO}" >> ${WRKSRC}/mkinstalldirs
	${CHMOD} 755  ${WRKSRC}/mkinstalldirs
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/share/whiteBOX/plugins

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
