# $NetBSD: Makefile,v 1.20 2009/06/30 00:07:25 joerg Exp $

DISTNAME=	xless-1.7
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 text viewer; useful as an add-on tool for other apps

MAKE_JOBS_SAFE=		no

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
