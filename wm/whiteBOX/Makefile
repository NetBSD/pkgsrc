# $NetBSD: Makefile,v 1.3 2002/12/17 08:19:34 jmmv Exp $
#

DISTNAME=		whiteBOX-0.5
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

.include "../../converters/libiconv/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
