# $NetBSD: Makefile,v 1.37 2005/03/24 21:13:04 wiz Exp $

DISTNAME=		tkman
PKGNAME=		tkman-2.1
CATEGORIES=		x11
MASTER_SITES=		ftp://tkman.sourceforge.net/pub/tkman/ \
			http://tkman.sourceforge.net/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tkman.sourceforge.net/
COMMENT=		Tcl/Tk based manual browser

DEPENDS+=		glimpse>=4.1:../../textproc/glimpse
DEPENDS+=		tk>=8.3.2:../../x11/tk83

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_RMAN=		yes
USE_X11=		yes

post-install:
	${SED} -e 's|@@LOCALBASE@@|${LOCALBASE}|' \
		-e 's|@@PREFIX@@|${PREFIX}|' \
		-e 's|@@X11BASE@@|${X11BASE}|' \
		${FILESDIR}/mkindex > ${WRKDIR}/mkindex
	${INSTALL_SCRIPT} ${WRKDIR}/mkindex ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
