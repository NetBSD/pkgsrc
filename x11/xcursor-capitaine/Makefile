# $NetBSD: Makefile,v 1.1 2018/11/24 13:09:57 nia Exp $

DISTNAME=	xcursor-capitaine-2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=keeferrourke/}
GITHUB_PROJECT=	capitaine-cursors
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/keeferrourke/capitaine-cursors
COMMENT=	Cursor theme inspired by macOS and based on KDE Breeze
LICENSE=	gnu-lgpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes

ICON_THEMES=	yes

INSTALLATION_DIRS+=	share/icons/capitaine-cursors
INSTALLATION_DIRS+=	share/icons/capitaine-cursors/cursors

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/index.theme \
	    ${DESTDIR}${PREFIX}/share/icons/capitaine-cursors
	${INSTALL_DATA} ${WRKSRC}/dist/cursors/* \
	    ${DESTDIR}${PREFIX}/share/icons/capitaine-cursors/cursors

.include "../../mk/bsd.pkg.mk"
