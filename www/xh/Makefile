# $NetBSD: Makefile,v 1.2 2022/05/23 07:06:54 pin Exp $

DISTNAME=	xh-0.16.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ducaale/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ducaale/xh/
COMMENT=	Friendly and fast tool for sending HTTP requests
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/xh/auto-completion

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xh \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xh.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xh.1
	${INSTALL_DATA} ${WRKSRC}/completions/xh.bash \
		${DESTDIR}${PREFIX}/share/examples/xh/auto-completion
	${INSTALL_DATA} ${WRKSRC}/completions/xh.fish \
		${DESTDIR}${PREFIX}/share/examples/xh/auto-completion
	${INSTALL_DATA} ${WRKSRC}/completions/_xh \
		${DESTDIR}${PREFIX}/share/examples/xh/auto-completion
	${INSTALL_DATA} ${WRKSRC}/completions/_xh.ps1 \
		${DESTDIR}${PREFIX}/share/examples/xh/auto-completion

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
