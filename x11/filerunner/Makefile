# $NetBSD: Makefile,v 1.7 1998/08/20 15:17:33 tsarna Exp $
# $FreeBSD Id: Makefile,v 1.12 1998/02/24 21:43:11 jseger Exp
#

DISTNAME=	FileRunner-2.4.2
PKGNAME=	filerunner-2.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cd.chalmers.se/~hch/filerunner.html

DEPENDS+=	tk-8.0p2:../../x11/tk80

USE_X11=	yes

post-extract:
	${RM} ${WRKSRC}/ext.so
	${CP} ${WRKSRC}/Makefiles/Makefile.netbsd_gcc ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in FAQ HISTORY QuickStart.txt Tips Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl frcolor frftp ftp.tcl http.tcl tclIndex
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include "../../mk/bsd.pkg.mk"
