# $NetBSD: Makefile,v 1.5 2000/03/02 15:47:35 itojun Exp $

DISTNAME=	w3m-0.1.6
CATEGORIES=	www
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/w3m/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/w3m/

DEPENDS=	boehm-gc-5.0a3:../../devel/boehm-gc

.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS=	-c w3m/gc\*
.else
EXTRACT_ELEMENTS=	--exclude w3m/gc\*
.endif

WRKSRC=		${WRKDIR}/w3m
HELPDIR=	share/doc/w3m
HELPERDIR=	lib/w3m

HAS_CONFIGURE=	yes

# configure will check IPv6 readiness automatically
BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"

# Set this to NO for ISO-8859-1 support (exclusive to Japanese).
W3M_USE_JAPANESE?=	YES
# Set this to YES to use lynx like key binding.
W3M_USE_LYNX_KEY?=	NO

.if defined(W3M_USE_JAPANESE) && ${W3M_USE_JAPANESE} == YES
CONFIGURE_ENV+=	def_lg=1
CONFIGURE_ENV+=	def_dcode=n
CONFIGURE_ENV+=	def_kanji_symbols=y
HELP_LANG=	_ja
.else
CONFIGURE_ENV+=	def_lg=2
CONFIGURE_ENV+=	def_kanji_symbols=n
HELP_LANG=	_en
.endif
.if defined(W3M_USE_LYNX_KEY) && ${W3M_USE_LYNX_KEY} == YES
CONFIGURE_ENV+=	def_lynx_key=y
HELP_LYNX=	-lynx
.else
CONFIGURE_ENV+=	def_lynx_key=n
.endif
CONFIGURE_ENV+=	def_bindir=${LOCALBASE}/bin
CONFIGURE_ENV+=	def_libdir=${LOCALBASE}/${HELPERDIR}
CONFIGURE_ENV+=	def_helpdir=${LOCALBASE}/${HELPDIR}
CONFIGURE_ENV+=	def_use_color=y def_use_mouse=y
CONFIGURE_ENV+=	def_use_menu=y def_use_matrix=y
CONFIGURE_ENV+=	editor=vi dmail=Mail dbrowser=
CONFIGURE_ENV+=	cc="${CC}" termlib="-ltermcap"
CONFIGURE_ENV+=	dldflags="-Wl,-rpath,${LOCALBASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_ENV+=	dmodel=1
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"

post-extract:
	@(cd ${WRKSRC}/doc; ${RM} -fr CVS)
	@(cd ${WRKSRC}/doc-jp; ${RM} -fr CVS)

do-configure:
	@yes '' | (cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    CFLAGS="${CFLAGS}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

pre-build:
	@(cd ${WRKSRC}; \
	 ${MAKE} XXMakefile; \
	 ${MV} XXMakefile XXMakefile.gen; \
	 ${SED} -e '/^GCLIB/s|gc/gc.a|-lgc|' -e '/^GCTARGET/s|gc/gc.a||' \
		XXMakefile.gen > XXMakefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/w3m ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/w3m.1 ${LOCALBASE}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc-jp/w3m.1 ${LOCALBASE}/man/ja_JP.EUC/man1
	${INSTALL_DATA_DIR} ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA_DIR} ${LOCALBASE}/${HELPDIR}/doc
	${INSTALL_DATA_DIR} ${LOCALBASE}/${HELPDIR}/doc-jp
	${INSTALL_DATA} ${WRKSRC}/w3mhelp_en.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp_ja.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-lynx_en.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-lynx_ja.html ${LOCALBASE}/${HELPDIR}
	(cd ${WRKSRC}/doc; ${GTAR} Bcf - .) | \
	    (cd ${LOCALBASE}/${HELPDIR}/doc; ${GTAR} Bxf -)
	(cd ${WRKSRC}/doc-jp; ${GTAR} Bcf - .) | \
	    (cd ${LOCALBASE}/${HELPDIR}/doc-jp; ${GTAR} Bxf -)
	${INSTALL_DATA_DIR} ${LOCALBASE}/${HELPERDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/w3mbookmark ${LOCALBASE}/${HELPERDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/w3mhelperpanel ${LOCALBASE}/${HELPERDIR}

post-install:
	(cd ${LOCALBASE}/${HELPDIR}; \
	    ${RM} -f w3mhelp.html; \
	    ${LN} -s w3mhelp${HELP_LYNX}${HELP_LANG}.html w3mhelp.html)

.include "../../mk/bsd.pkg.mk"
