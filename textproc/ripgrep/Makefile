# $NetBSD: Makefile,v 1.24 2025/02/24 21:52:08 kim Exp $

DISTNAME=	ripgrep-14.1.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/ripgrep/
COMMENT=	Line-oriented search tool
LICENSE=	unlicense

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		pcre2

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} != "yes"
RIPGREP=	${WRKSRC}/target/release/rg
.else
TOOL_DEPENDS+=	${PKGNAME}:../../${PKGPATH}
RIPGREP=	${TOOLBASE}/bin/rg
.endif

post-build:
	@${STEP_MSG} "Creating manual page..."
	${RUN}${RIPGREP} --generate man > ${WRKDIR}/rg.1
	@${STEP_MSG} "Creating completion rules..."
	${RUN}${RIPGREP} --generate complete-bash \
	  > ${WRKDIR}/rg-completion.bash
	${RUN}${RIPGREP} --generate complete-fish \
	  > ${WRKDIR}/rg-completion.fish
	${RUN}${RIPGREP} --generate complete-zsh \
	  > ${WRKDIR}/rg-completion.zsh

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_MAN} ${WRKDIR}/rg.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rg.1
	${INSTALL_DATA} ${WRKDIR}/rg-completion.bash \
	  ${DESTDIR}${PREFIX}/share/bash-completion/completions/rg
	${INSTALL_DATA} ${WRKDIR}/rg-completion.fish \
	  ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/rg.fish
	${INSTALL_DATA} ${WRKDIR}/rg-completion.zsh \
	  ${DESTDIR}${PREFIX}/share/zsh/site-functions/_rg

.include "../../lang/rust/cargo.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
