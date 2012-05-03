# $NetBSD: Makefile,v 1.22 2012/05/03 09:55:32 obache Exp $

DISTNAME=	xless-1.7
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 text viewer; useful as an add-on tool for other apps

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_IMAKE=	yes

INSTALLATION_DIRS=	lib/X11

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
