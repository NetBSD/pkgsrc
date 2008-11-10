# $NetBSD: Makefile,v 1.19 2008/11/10 17:21:39 wiz Exp $

DISTNAME=	xless-1.7
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 text viewer; useful as an add-on tool for other apps

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
