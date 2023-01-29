# $NetBSD: Makefile,v 1.32 2023/01/29 21:17:58 ryoon Exp $

DISTNAME=	flwm-1.16
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	flwm
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/flwm
COMMENT=	The Fast, Light Window Manager
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
