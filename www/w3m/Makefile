# $NetBSD: Makefile,v 1.29 2001/11/29 01:12:52 hubertf Exp $
#

DISTNAME=	w3m-0.2.1
PKGNAME=	w3m-0.2.1.0.19
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/w3m/

PATCH_SITES=	http://www2u.biglobe.ne.jp/~hsaka/w3m/patch/
PATCHFILES=	w3m-0.2.1-m17n-0.19.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www2u.biglobe.ne.jp/~hsaka/w3m/
COMMENT=	multilingualized version of a pager/text-based browser w3m

DEPENDS=	boehm-gc>=5.3:../../devel/boehm-gc

CONFLICTS+=	w3m-m17n-[0-9]*

HELPDIR=        share/doc/w3m
HELPERDIR=      lib/w3m

# configure will check IPv6 readiness automatically
BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS=	-c ${DISTNAME}/gc/\*
.else
EXTRACT_ELEMENTS=	--exclude ${DISTNAME}/gc/\*
.endif

# Always enable multiligualization.
W3M_USE_M17N=			YES
# Set this to YES if you want unicode support.
W3M_USE_UNICODE?=		YES
# set this to YES to use Japanese messages.
W3M_USE_JAPANESE_MESSAGES?=	NO
# Set this to YES to use lynx like key binding.
W3M_USE_LYNX_KEY?=		NO
# set this to YES if you want HTTPS support.
W3M_USE_SSL?=			YES
# set this to YES if you want HTTP cookie support.
W3M_USE_COOKIE?=        	YES
# set this to YES if you want mouse support.
W3M_USE_MOUSE?=			YES
# set this to YES if you want color support.
W3M_USE_COLOR?=			YES

CONFIGURE_ENV+=	use_m17n=y
.if ${W3M_USE_UNICODE} == YES
CONFIGURE_ENV+=	use_unicode=y
.else
CONFIGURE_ENV+=	use_unicode=n
.endif
CONFIGURE_ENV+=	charset=ISO-2022-JP-2
.if ${W3M_USE_JAPANESE_MESSAGES} == YES
CONFIGURE_ENV+=	lang=ja
HELP_LANG=			_ja
.else
CONFIGURE_ENV+=	lang=en
HELP_LANG=			_en
.endif
.if ${W3M_USE_COLOR} == YES
CONFIGURE_ENV+=	use_color=y
.else
CONFIGURE_ENV+=	use_color=n
.endif
.if ${W3M_USE_MOUSE} == YES
CONFIGURE_ENV+=	use_mouse=y
.else
CONFIGURE_ENV+=	use_mouse=n
.endif
.if ${W3M_USE_COOKIE} == YES
CONFIGURE_ENV+=	use_cookie=y
.else
CONFIGURE_ENV+=	use_cookie=n
.endif
.if ${W3M_USE_SSL} == YES
USE_SSL=			YES
CONFIGURE_ENV+=	use_ssl=y use_ssl_verify=n
.else
CONFIGURE_ENV+=	use_ssl=n use_ssl_verify=n
.endif
.if ${W3M_USE_LYNX_KEY} == YES
CONFIGURE_ENV+=	lynx_key=y
HELP_W3M=			-lynx
.else
CONFIGURE_ENV+=	lynx_key=n
HELP_W3M=			-w3m
.endif
CONFIGURE_ENV+= def_bindir=${LOCALBASE}/bin
CONFIGURE_ENV+= def_libdir=${LOCALBASE}/${HELPERDIR}
CONFIGURE_ENV+= def_helpdir=${LOCALBASE}/${HELPDIR}
CONFIGURE_ENV+= use_menu=y use_matrix=n ansi_color=y
CONFIGURE_ENV+= ded=vi dmail=Mail dbrowser=
CONFIGURE_ENV+= dcc="${CC}" dtermlib="-ltermcap"
CONFIGURE_ENV+= dldflags="-Wl,-rpath,${LOCALBASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_ENV+= dmodel=6
CONFIGURE_ENV+= LOCALBASE="${LOCALBASE}"
CONFIGURE_ARGS+= -suffix=

post-extract:
	@(cd ${WRKSRC}/doc; ${RM} -fr CVS)
	@(cd ${WRKSRC}/doc-jp; ${RM} -fr CVS)

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM}

# do not look at previous configuration
do-configure:
	@yes '' | (cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" \
	    INSTALL="${INSTALL_SCRIPT}"                             \
	    CFLAGS="${CFLAGS}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

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
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-w3m_en.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-w3m_ja.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-lynx_en.html ${LOCALBASE}/${HELPDIR}
	${INSTALL_DATA} ${WRKSRC}/w3mhelp-lynx_ja.html ${LOCALBASE}/${HELPDIR}
	# Use ${PAX} to discard uid/gid
	(cd ${WRKSRC}; ${PAX} -w doc doc-jp) | \
	    (cd ${LOCALBASE}/${HELPDIR}; ${PAX} -r)
	${INSTALL_DATA_DIR} ${LOCALBASE}/${HELPERDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/w3mbookmark ${LOCALBASE}/${HELPERDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/w3mhelperpanel ${LOCALBASE}/${HELPERDIR}

post-install:
	(cd ${LOCALBASE}/${HELPDIR}; \
	    ${RM} -f w3mhelp.html; \
	    ${LN} -s w3mhelp${HELP_W3M}${HELP_LANG}.html w3mhelp.html)

.include "../../mk/bsd.pkg.mk"
