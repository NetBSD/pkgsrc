# New ports collection makefile for:	filerunner
# Version required:	2.4.1
# Date created:		3 August 1996
# Whom:			lukin
#
# $NetBSD: Makefile,v 1.3 1998/03/24 09:54:56 tron Exp $
# $FreeBSD Id: Makefile,v 1.12 1998/02/24 21:43:11 jseger Exp
#

DISTNAME=	FileRunner_2.4.1
PKGNAME=	filerunner-2.4.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.tgz

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11/tk80

USE_X11=	yes
WRKSRC=		${WRKDIR}/FileRunner_2.4.1

post-extract:
	@${RM} ${WRKSRC}/ext.so
	@${CP} ${WRKSRC}/Makefiles/Makefile.netbsd ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	@${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in FAQ HISTORY QuickStart.txt Tips Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl frcolor frftp ftp.tcl http.tcl tclIndex
		@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		@${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include <bsd.port.mk>
