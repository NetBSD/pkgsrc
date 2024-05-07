# $NetBSD: Makefile,v 1.5 2024/05/07 11:39:33 nat Exp $

VERSION=	0.3
GITHUB_PROJECT=	tinyx-wscons
DISTNAME=	${GITHUB_PROJECT}-${VERSION}

CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=AceHusky12/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nat@NetBSD.org
HOMEPAGE=	https://github.com/AceHusky12/tinyx-wscons
COMMENT=	Minimal X11 from Tiny Core Linux with wscons support
LICENSE=	gnu-gpl-v3

ONLY_FOR_PLATFORM=	NetBSD-* OpenBSD-*

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake aclocal autoconf automake pkg-config
INSTALLATION_DIRS=	sbin
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

SPECIAL_PERMS+=		sbin/Xwscons ${SETUID_ROOT_PERMS}

pre-configure:
	cd ${WRKSRC} && ACLOCAL="aclocal -I ${X11BASE}/share/aclocal" \
	sh ./autogen.sh

do-configure:
	cd ${WRKSRC} && ./configure --prefix ${X11BASE}

do-install:
.for f in Xwscons
	${INSTALL_PROGRAM} ${WRKSRC}/kdrive/wscons/${f} ${DESTDIR}${PREFIX}/sbin
.endfor


.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
