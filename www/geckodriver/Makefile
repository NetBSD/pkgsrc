# $NetBSD: Makefile,v 1.7 2019/01/05 03:01:30 tnn Exp $

DISTNAME=	geckodriver-0.23.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_PROJECT=	geckodriver
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/geckodriver/
COMMENT=	W3C WebDriver-compatible proxy for Gecko-based browsers
LICENSE=	mpl-1.1

CARGO_CRATE_DEPENDS+=	adler32-1.0.3
CARGO_CRATE_DEPENDS+=	aho-corasick-0.6.9
CARGO_CRATE_DEPENDS+=	arrayvec-0.4.10
CARGO_CRATE_DEPENDS+=	autocfg-0.1.1
CARGO_CRATE_DEPENDS+=	base64-0.9.3
CARGO_CRATE_DEPENDS+=	bitflags-1.0.4
CARGO_CRATE_DEPENDS+=	build_const-0.2.1
CARGO_CRATE_DEPENDS+=	byteorder-1.2.7
CARGO_CRATE_DEPENDS+=	bytes-0.4.11
CARGO_CRATE_DEPENDS+=	bzip2-0.3.3
CARGO_CRATE_DEPENDS+=	bzip2-sys-0.1.7
CARGO_CRATE_DEPENDS+=	cc-1.0.28
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.6
CARGO_CRATE_DEPENDS+=	chrono-0.4.6
CARGO_CRATE_DEPENDS+=	clap-2.32.0
CARGO_CRATE_DEPENDS+=	cloudabi-0.0.3
CARGO_CRATE_DEPENDS+=	cookie-0.11.0
CARGO_CRATE_DEPENDS+=	crc-1.8.1
CARGO_CRATE_DEPENDS+=	crc32fast-1.1.2
CARGO_CRATE_DEPENDS+=	crossbeam-deque-0.6.3
CARGO_CRATE_DEPENDS+=	crossbeam-epoch-0.7.0
CARGO_CRATE_DEPENDS+=	crossbeam-utils-0.6.3
CARGO_CRATE_DEPENDS+=	flate2-1.0.6
CARGO_CRATE_DEPENDS+=	fnv-1.0.6
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	futures-0.1.25
CARGO_CRATE_DEPENDS+=	futures-cpupool-0.1.8
CARGO_CRATE_DEPENDS+=	h2-0.1.14
CARGO_CRATE_DEPENDS+=	http-0.1.14
CARGO_CRATE_DEPENDS+=	httparse-1.3.3
CARGO_CRATE_DEPENDS+=	hyper-0.12.19
CARGO_CRATE_DEPENDS+=	idna-0.1.5
CARGO_CRATE_DEPENDS+=	indexmap-1.0.2
CARGO_CRATE_DEPENDS+=	iovec-0.1.2
CARGO_CRATE_DEPENDS+=	itoa-0.4.3
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.2.0
CARGO_CRATE_DEPENDS+=	lazycell-1.2.1
CARGO_CRATE_DEPENDS+=	libc-0.2.46
CARGO_CRATE_DEPENDS+=	lock_api-0.1.5
CARGO_CRATE_DEPENDS+=	log-0.4.6
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.1.2
CARGO_CRATE_DEPENDS+=	memoffset-0.2.1
CARGO_CRATE_DEPENDS+=	miniz_oxide-0.2.0
CARGO_CRATE_DEPENDS+=	miniz_oxide_c_api-0.2.0
CARGO_CRATE_DEPENDS+=	mio-0.6.16
CARGO_CRATE_DEPENDS+=	mio-uds-0.6.7
CARGO_CRATE_DEPENDS+=	miow-0.2.1
CARGO_CRATE_DEPENDS+=	mozprofile-0.4.0
CARGO_CRATE_DEPENDS+=	mozrunner-0.8.0
CARGO_CRATE_DEPENDS+=	mozversion-0.1.3
CARGO_CRATE_DEPENDS+=	msdos_time-0.1.6
CARGO_CRATE_DEPENDS+=	net2-0.2.33
CARGO_CRATE_DEPENDS+=	nodrop-0.1.13
CARGO_CRATE_DEPENDS+=	num-integer-0.1.39
CARGO_CRATE_DEPENDS+=	num-traits-0.2.6
CARGO_CRATE_DEPENDS+=	num_cpus-1.9.0
CARGO_CRATE_DEPENDS+=	owning_ref-0.4.0
CARGO_CRATE_DEPENDS+=	parking_lot-0.6.4
CARGO_CRATE_DEPENDS+=	parking_lot_core-0.3.1
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	podio-0.1.6
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.24
CARGO_CRATE_DEPENDS+=	quote-0.6.10
CARGO_CRATE_DEPENDS+=	rand-0.3.22
CARGO_CRATE_DEPENDS+=	rand-0.4.3
CARGO_CRATE_DEPENDS+=	rand-0.5.5
CARGO_CRATE_DEPENDS+=	rand-0.6.3
CARGO_CRATE_DEPENDS+=	rand_chacha-0.1.1
CARGO_CRATE_DEPENDS+=	rand_core-0.2.2
CARGO_CRATE_DEPENDS+=	rand_core-0.3.0
CARGO_CRATE_DEPENDS+=	rand_hc-0.1.0
CARGO_CRATE_DEPENDS+=	rand_isaac-0.1.1
CARGO_CRATE_DEPENDS+=	rand_os-0.1.0
CARGO_CRATE_DEPENDS+=	rand_pcg-0.1.1
CARGO_CRATE_DEPENDS+=	rand_xorshift-0.1.1
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.50
CARGO_CRATE_DEPENDS+=	regex-0.2.11
CARGO_CRATE_DEPENDS+=	regex-1.1.0
CARGO_CRATE_DEPENDS+=	regex-syntax-0.5.6
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.4
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.1
CARGO_CRATE_DEPENDS+=	rust-ini-0.10.3
CARGO_CRATE_DEPENDS+=	rustc_version-0.2.3
CARGO_CRATE_DEPENDS+=	ryu-0.2.7
CARGO_CRATE_DEPENDS+=	safemem-0.3.0
CARGO_CRATE_DEPENDS+=	scopeguard-0.3.3
CARGO_CRATE_DEPENDS+=	semver-0.6.0
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	serde-1.0.84
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.84
CARGO_CRATE_DEPENDS+=	serde_json-1.0.34
CARGO_CRATE_DEPENDS+=	slab-0.4.1
CARGO_CRATE_DEPENDS+=	smallvec-0.6.7
CARGO_CRATE_DEPENDS+=	stable_deref_trait-1.1.1
CARGO_CRATE_DEPENDS+=	string-0.1.2
CARGO_CRATE_DEPENDS+=	strsim-0.7.0
CARGO_CRATE_DEPENDS+=	syn-0.15.23
CARGO_CRATE_DEPENDS+=	tempdir-0.3.7
CARGO_CRATE_DEPENDS+=	term_size-0.3.1
CARGO_CRATE_DEPENDS+=	textwrap-0.10.0
CARGO_CRATE_DEPENDS+=	thread_local-0.3.6
CARGO_CRATE_DEPENDS+=	time-0.1.41
CARGO_CRATE_DEPENDS+=	tokio-0.1.13
CARGO_CRATE_DEPENDS+=	tokio-codec-0.1.1
CARGO_CRATE_DEPENDS+=	tokio-current-thread-0.1.4
CARGO_CRATE_DEPENDS+=	tokio-executor-0.1.5
CARGO_CRATE_DEPENDS+=	tokio-fs-0.1.4
CARGO_CRATE_DEPENDS+=	tokio-io-0.1.10
CARGO_CRATE_DEPENDS+=	tokio-reactor-0.1.7
CARGO_CRATE_DEPENDS+=	tokio-tcp-0.1.2
CARGO_CRATE_DEPENDS+=	tokio-threadpool-0.1.9
CARGO_CRATE_DEPENDS+=	tokio-timer-0.2.8
CARGO_CRATE_DEPENDS+=	tokio-udp-0.1.3
CARGO_CRATE_DEPENDS+=	tokio-uds-0.2.4
CARGO_CRATE_DEPENDS+=	try-lock-0.2.2
CARGO_CRATE_DEPENDS+=	ucd-util-0.1.3
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.7
CARGO_CRATE_DEPENDS+=	unicode-segmentation-1.2.1
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	unreachable-1.0.0
CARGO_CRATE_DEPENDS+=	url-1.7.2
CARGO_CRATE_DEPENDS+=	utf8-ranges-1.0.2
CARGO_CRATE_DEPENDS+=	uuid-0.5.1
CARGO_CRATE_DEPENDS+=	version_check-0.1.5
CARGO_CRATE_DEPENDS+=	void-1.0.2
CARGO_CRATE_DEPENDS+=	want-0.0.6
CARGO_CRATE_DEPENDS+=	webdriver-0.38.0
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.6
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winreg-0.5.1
CARGO_CRATE_DEPENDS+=	ws2_32-sys-0.2.1
CARGO_CRATE_DEPENDS+=	zip-0.4.2

INSTALLATION_DIRS=	bin

# Mozilla stopped providing a standalone Cargo.lock for geckodriver.
# So, we have to maintain a local copy.
post-extract:
	cp ${FILESDIR}/Cargo.lock ${WRKSRC}/Cargo.lock

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/geckodriver ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
