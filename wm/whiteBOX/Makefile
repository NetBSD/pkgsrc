# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:38 wiz Exp $
#

DISTNAME=		whiteBOX-0.5
PKGREVISION=	2
CATEGORIES=		wm x11
MASTER_SITES=		http://whitebox.sourceforge.net/dist/

MAINTAINER=		jschauma@netbsd.org
HOMEPAGE=		http://whitebox.sourceforge.net/
COMMENT=		Multi-purpose configuration tool for Blackbox

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
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
