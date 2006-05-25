# $NetBSD: Makefile,v 1.42 2006/05/25 10:43:38 wiz Exp $

DISTNAME=		tkman-2.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tkman/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tkman.sourceforge.net/
COMMENT=		Tcl/Tk based manual browser

DEPENDS+=		glimpse>=4.1:../../textproc/glimpse
DEPENDS+=		rman>=3.1:../../textproc/rman
DEPENDS+=		tk>=8.4:../../x11/tk

post-extract:
.for f in Makefile manpath.tcl
	${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.cr
	${TR} -d '\r' < ${WRKSRC}/${f}.cr > ${WRKSRC}/${f}
.endfor

post-install:
	${SED} -e 's|@@LOCALBASE@@|${LOCALBASE}|' \
		-e 's|@@PREFIX@@|${PREFIX}|' \
		-e 's|@@X11BASE@@|${X11BASE}|' \
		${FILESDIR}/mkindex > ${WRKDIR}/mkindex
	${INSTALL_SCRIPT} ${WRKDIR}/mkindex ${PREFIX}/libexec

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
