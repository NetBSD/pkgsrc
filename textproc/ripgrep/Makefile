# $NetBSD: Makefile,v 1.3 2018/10/25 00:35:22 minskim Exp $

GITHUB_PROJECT=	ripgrep
DISTNAME=	0.8.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	maya@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/ripgrep/
COMMENT=	Line-oriented search tool
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/ripgrep-0.8.1
USE_LANGUAGES=	c

CARGO_CRATE_DEPENDS+=		\
	atty-0.2.6		\
	bytecount-0.3.1		\
	cfg-if-0.1.2		\
	clap-2.30.0		\
	crossbeam-0.3.2		\
	encoding_rs-0.7.2	\
	glob-0.2.11		\
	globset-0.3.0		\
	grep-0.1.8		\
	ignore-0.4.0		\
	lazy_static-1.0.0	\
	libc-0.2.36		\
	log-0.4.1		\
	memchr-2.0.1		\
	memmap-0.6.2		\
	num_cpus-1.8.0		\
	regex-0.2.6		\
	regex-syntax-0.4.2	\
	same-file-1.0.2		\
	simd-0.2.1		\
	aho-corasick-0.6.4	\
	fnv-1.0.6		\
	termcolor-0.3.4		\
	termion-1.5.1		\
	redox_syscall-0.1.37	\
	redox_termios-0.1.1	\
	strsim-0.7.0		\
	textwrap-0.9.0		\
	unicode-width-0.1.4	\
	ansi_term-0.10.2	\
	thread_local-0.3.5	\
	walkdir-2.1.4		\
	winapi-0.3.4		\
	winapi-i686-pc-windows-gnu-0.4.0	\
	winapi-x86_64-pc-windows-gnu-0.4.0	\
	utf8-ranges-1.0.0	\
	unreachable-1.0.0	\
	tempdir-0.3.5		\
	void-1.0.2		\
	rand-0.4.2		\
	rand-0.3.22		\
	fuchsia-zircon-0.3.3	\
	fuchsia-zircon-sys-0.3.3	\
	bitflags-1.0.1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/cargo install --root ${DESTDIR}${PREFIX}
	rm ${DESTDIR}${PREFIX}/.crates.toml

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
