# $NetBSD: Makefile,v 1.23 2000/08/31 03:58:14 fredb Exp $
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

.include "../../mk/bsd.pkg.mk"
