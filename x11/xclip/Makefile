# $NetBSD: Makefile,v 1.18 2014/04/30 06:25:54 wiz Exp $

DISTNAME=	xclip-0.12
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xclip/
COMMENT=	Command line interface to the X windows clipboard
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
