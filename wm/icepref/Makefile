# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:54 jlam Exp $
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

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
