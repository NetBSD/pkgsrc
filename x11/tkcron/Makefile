# $NetBSD: Makefile,v 1.9 1999/04/26 19:30:28 garbled Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/22 20:10:39 jseger Exp
#

DISTNAME=	tkcron-2.12
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	sander@haldjas.folklore.ee

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} > tkcron.tcl
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
