# $NetBSD: Makefile,v 1.30 2002/03/02 00:08:15 kei Exp $
#

DISTNAME=	w3m-0.2.5-m17n-20020216
PKGNAME=	w3m-0.2.5
CATEGORIES=	www
MASTER_SITES=	http://www2u.biglobe.ne.jp/~hsaka/w3m/patch/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www2u.biglobe.ne.jp/~hsaka/w3m/
COMMENT=	multilingualized version of a pager/text-based browser w3m

CONFLICTS+=	w3m-m17n-[0-9]*

USE_BUILDLINK_ONLY=	yes

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
CONFIGURE_ARGS+=	--lang=ja
HELP_LANG=			_ja
.else
CONFIGURE_ARGS+=	--lang=en
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
CONFIGURE_ARGS+=	--ssl-includedir=${BUILDLINK_DIR}/include/openssl
CONFIGURE_ARGS+=	--ssl-libdir=${BUILDLINK_DIR}/lib
.include "../../security/openssl/buildlink.mk"
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
CONFIGURE_ENV+= use_menu=y use_matrix=n ansi_color=y
CONFIGURE_ENV+= ded=vi dmail=Mail dbrowser=
CONFIGURE_ENV+= dcc="${CC}" dtermlib="-ltermcap"
CONFIGURE_ENV+= dldflags="-Wl,-rpath,${LOCALBASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_ENV+= dmodel=6
CONFIGURE_ENV+= LOCALBASE="${LOCALBASE}"
CONFIGURE_ARGS+= --yes
CONFIGURE_ARGS+= --suffix=
CONFIGURE_ARGS+= --prefix=${PREFIX}
CONFIGURE_ARGS+= --bindir=${PREFIX}/bin
CONFIGURE_ARGS+= --libdir=${PREFIX}/${HELPERDIR}
CONFIGURE_ARGS+= --helpdir=${PREFIX}/${HELPDIR}
CONFIGURE_ARGS+= --gc-includedir=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+= --gc-libdir=${BUILDLINK_DIR}/lib

post-extract:
	@(cd ${WRKSRC}/doc; ${RM} -fr CVS)
	@(cd ${WRKSRC}/doc-jp; ${RM} -fr CVS)

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM}

# do not look at previous configuration
do-configure:
	@(cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" \
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

.include "../../devel/boehm-gc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
