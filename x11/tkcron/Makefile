# $NetBSD: Makefile,v 1.6 1998/10/15 19:51:08 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/22 20:10:39 jseger Exp
#

DISTNAME=	tkcron-2.12
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	sander@haldjas.folklore.ee

RUN_DEPENDS=	wish8.0:../../x11/tk80

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
