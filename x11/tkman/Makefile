# $NetBSD: Makefile,v 1.25 2001/01/29 11:34:49 wiz Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman
PKGNAME=		tkman-2.1
CATEGORIES=		x11
MASTER_SITES=		ftp://tkman.sourceforge.net/pub/tkman/ \
			http://tkman.sourceforge.net/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://tkman.sourceforge.net/

DEPENDS+=		glimpse-4.1:../../textproc/glimpse
DEPENDS+=		rman-3.0.*:../../textproc/rman
DEPENDS+=		tk-8.3.2:../../x11/tk

USE_X11=		yes

WRKSRC=			${WRKDIR}/${PKGNAME}

post-install:
	${SED} -e 's|@@LOCALBASE@@|${LOCALBASE}|' \
		-e 's|@@PREFIX@@|${PREFIX}|' \
		-e 's|@@X11BASE@@|${X11BASE}|' \
		< ${FILESDIR}/mkindex > ${WRKDIR}/mkindex
	${INSTALL_SCRIPT} ${WRKDIR}/mkindex ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
