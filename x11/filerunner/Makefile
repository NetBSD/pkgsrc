# $NetBSD: Makefile,v 1.16 2001/05/05 19:51:19 jlam Exp $
# $FreeBSD Id: Makefile,v 1.12 1998/02/24 21:43:11 jseger Exp
#

DISTNAME=	FileRunner-2.4.2
PKGNAME=	filerunner-2.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/desktop/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cd.chalmers.se/~hch/filerunner.html
COMMENT=	Filemanager with FTP capabilities. Uses Tcl/Tk

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11BASE=	yes

post-extract:
	${RM} ${WRKSRC}/ext.so
	${CP} ${WRKSRC}/Makefiles/Makefile.netbsd_gcc ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/FileRunner/bitmaps
	${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	${LN} -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for FILE in FAQ HISTORY QuickStart.txt Tips Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl ftp.tcl http.tcl tclIndex
		${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/lib/FileRunner
.endfor
.for FILE in frcolor frftp
		${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include "../../mk/bsd.pkg.mk"
