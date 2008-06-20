# $NetBSD: Makefile,v 1.4 2008/06/20 01:09:44 joerg Exp $
#

DISTNAME=	BWidget-1.8.0
PKGNAME=	${DISTNAME:S/BW/bw/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcllib.sourceforge.net/
COMMENT=	High-level widget set for Tcl/Tk

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_TOOLS+=	wish:run pax

INSTALLATION_DIRS=	lib/bwidget share/doc/bwidget

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DESTDIR}${PREFIX}/lib/bwidget
	cd ${WRKSRC} && \
	pax -rw -pm lang ${DESTDIR}${PREFIX}/lib/bwidget && \
	pax -rw -pm images ${DESTDIR}${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* ${DESTDIR}${PREFIX}/share/doc/bwidget

.include "../../mk/bsd.pkg.mk"
