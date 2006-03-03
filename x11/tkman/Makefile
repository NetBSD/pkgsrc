# $NetBSD: Makefile,v 1.40 2006/03/03 04:03:28 minskim Exp $

DISTNAME=		tkman-2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tkman/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tkman.sourceforge.net/
COMMENT=		Tcl/Tk based manual browser

DEPENDS+=		glimpse>=4.1:../../textproc/glimpse
DEPENDS+=		tk>=8.4:../../x11/tk

USE_RMAN=		yes

.include "../../mk/x11.buildlink3.mk"

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

.include "../../mk/bsd.pkg.mk"
