# $NetBSD: Makefile,v 1.6 2024/04/28 12:12:55 pho Exp $

DISTNAME=	open-browser-0.2.1.0
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Open a web browser from Haskell
LICENSE=	modified-bsd

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
.endif

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
