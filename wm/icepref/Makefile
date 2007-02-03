# $NetBSD: Makefile,v 1.17 2007/02/03 11:46:56 rillig Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	7
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	Graphical configuration utility for IceWM

WRKSRC=		${WRKDIR}/icepref

PYTHON_PATCH_SCRIPTS=	icepref

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icepref ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/icepref.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
