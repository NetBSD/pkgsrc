# $NetBSD: Makefile,v 1.3 1999/09/28 07:20:08 sakamoto Exp $

DISTNAME=	w3m-990902
PKGNAME=	w3m-19990902
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

HAS_CONFIGURE=	yes

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
CONFIGURE_ENV+=	def_helpdir=${LOCALBASE}/${HELPDIR}
CONFIGURE_ENV+=	def_use_color=y def_use_mouse=y
CONFIGURE_ENV+=	def_use_menu=y def_use_matrix=y
CONFIGURE_ENV+=	editor=vi mailer=Mail dbrowser=
CONFIGURE_ENV+=	cc="${CC}" termlib="-ltermcap"
CONFIGURE_ENV+=	dldflags="-Wl,-rpath,${LOCALBASE}/lib -L${LOCALBASE}/lib"

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
	${INSTALL_DATA} ${WRKSRC}/doc/* ${LOCALBASE}/${HELPDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc-jp/* ${LOCALBASE}/${HELPDIR}/doc-jp

post-install:
	${RM} -f ${LOCALBASE}/${HELPDIR}/w3mhelp.html
	${LN} -s ${LOCALBASE}/${HELPDIR}/w3mhelp${HELP_LYNX}${HELP_LANG}.html \
			${LOCALBASE}/${HELPDIR}/w3mhelp.html

.include "../../mk/bsd.pkg.mk"
