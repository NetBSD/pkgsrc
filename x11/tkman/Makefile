# $NetBSD: Makefile,v 1.35 2004/01/20 12:28:27 agc Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman
PKGNAME=		tkman-2.1
CATEGORIES=		x11
MASTER_SITES=		ftp://tkman.sourceforge.net/pub/tkman/ \
			http://tkman.sourceforge.net/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tkman.sourceforge.net/
COMMENT=		Tcl/Tk based manual browser

DEPENDS+=		glimpse>=4.1:../../textproc/glimpse
DEPENDS+=		tk>=8.3.2:../../x11/tk

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
