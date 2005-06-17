# $NetBSD: Makefile,v 1.25 2005/06/17 03:50:43 jlam Exp $

DISTNAME=	FileRunner-2.5.1
PKGNAME=	${DISTNAME:S/FileRunner/filerunner/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.cd.chalmers.se/~hch/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cd.chalmers.se/~hch/filerunner.html
COMMENT=	Filemanager with FTP capabilities. Uses Tcl/Tk

USE_X11BASE=	yes

INSTALLATION_DIRS=	bin

post-extract:
	${RM} ${WRKSRC}/ext.so
	${CP} ${WRKSRC}/Makefiles/Makefile.netbsd_gcc ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/FileRunner/bitmaps
	${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	${LN} -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for FILE in FAQ HISTORY QuickStart.txt Tips.txt Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog.tcl ext.so font.tcl ftp.tcl http.tcl tclIndex
		${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/lib/FileRunner
.endfor
.for FILE in frcolor frftp
		${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
