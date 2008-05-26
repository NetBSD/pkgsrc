# $NetBSD: Makefile,v 1.3 2008/05/26 02:13:26 joerg Exp $
#

DISTNAME=	BWidget-1.8.0
PKGNAME=	${DISTNAME:S/BW/bw/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcllib.sourceforge.net/
COMMENT=	High-level widget set for Tcl/Tk

NO_BUILD=	yes
USE_TOOLS+=	wish:run pax

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bwidget
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	cd ${WRKSRC} && \
	pax -rw -pm lang ${PREFIX}/lib/bwidget && \
	pax -rw -pm images ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* ${PREFIX}/share/doc/bwidget

.include "../../mk/bsd.pkg.mk"
