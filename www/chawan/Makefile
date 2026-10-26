# $NetBSD: Makefile,v 1.1 2026/10/26 10:48:39 wiz Exp $

DISTNAME=	v0.5.1
PKGNAME=	chawan-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~bptato/chawan/archive/
DIST_SUBDIR=	chawan

MAINTAINER=	ivan@ivanpollak.com
HOMEPAGE=	https://chawan.net/
COMMENT=	TUI web browser with CSS, inline image and JavaScript support
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/chawan-${DISTNAME}

USE_TOOLS+=	gmake pkg-config
MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

# gcc is stricter than clang and thus the incompatible-pointer-types error
# should be ignored.
.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-Wno-incompatible-pointer-types
.endif

.include "../../lang/nim/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../devel/pkgconf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
