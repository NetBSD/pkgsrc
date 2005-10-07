# $NetBSD: Makefile,v 1.3 2005/10/07 17:57:59 reed Exp $

DISTNAME=		sarg-1.4.1
CATEGORIES=		www
MASTER_SITES=		http://web.onda.com.br/orso/

PATCH_SITES=		http://web.onda.com.br/orso/patches/
PATCHFILES=		sarg-1.4.1-index.sort.patch

MAINTAINER=		mishka@terabyte.com.ua
HOMEPAGE=		http://web.onda.com.br/orso/
COMMENT=		Squid-Cache proxy server Analysis Report Generator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gcc					\
			--enable-bindir=${PREFIX}/sbin			\
			--enable-mandir=${PREFIX}/${PKGMANDIR}/man1	\
			--enable-sysconfdir=${PKG_SYSCONFDIR}

USE_PKGINSTALL=		yes

DIST_SUBDIR=		${DISTNAME}
PKG_SYSCONFSUBDIR=	sarg
EGDIR=			${PREFIX}/share/examples/sarg
EGLNG=			${EGDIR}/languages
CFLNG=			${PKG_SYSCONFDIR}/languages

SQUID_ACCESSLOG?=	/var/squid/logs/access.log
SARG_REPORTSDIR?=	/var/sarg

OWN_DIRS+=		${SARG_REPORTSDIR} ${CFLNG}

FILES_SUBST+=		SQUID_ACCESSLOG=${SQUID_ACCESSLOG}		\
			SARG_REPORTSDIR=${SARG_REPORTSDIR}
SUBST_CLASSES+=		sargconf
SUBST_MESSAGE.sargconf=	"[Adjust values in SARG configuration files]"
SUBST_STAGE.sargconf=	post-configure
SUBST_FILES.sargconf=	sarg.conf sarg.1
SUBST_SED.sargconf=	${FILES_SUBST_SED}

BUILD_DEFS+=		SQUID_ACCESSLOG SARG_REPORTSDIR
MAKE_ENV+=		PKG_FLAGS="-DSQUID_ACCESSLOG='\"${SQUID_ACCESSLOG}\"' \
			-DSARG_REPORTSDIR='\"${SARG_REPORTSDIR}\"'"	\
			EGDIR="${EGDIR}"

CONF_FILES=		${EGDIR}/sarg.conf ${PKG_SYSCONFDIR}/sarg.conf	\
			${EGDIR}/exclude_codes ${PKG_SYSCONFDIR}/exclude_codes \
			${EGLNG}/Bulgarian_windows1251			\
				${CFLNG}/Bulgarian_windows1251		\
			${EGLNG}/Catalan ${CFLNG}/Catalan		\
			${EGLNG}/Czech ${CFLNG}/Czech			\
			${EGLNG}/Dutch ${CFLNG}/Dutch			\
			${EGLNG}/English ${CFLNG}/English		\
			${EGLNG}/French ${CFLNG}/French			\
			${EGLNG}/German ${CFLNG}/German			\
			${EGLNG}/Hungarian ${CFLNG}/Hungarian		\
			${EGLNG}/Indonesian ${CFLNG}/Indonesian		\
			${EGLNG}/Italian ${CFLNG}/Italian		\
			${EGLNG}/Japanese ${CFLNG}/Japanese		\
			${EGLNG}/Latvian ${CFLNG}/Latvian		\
			${EGLNG}/Polish ${CFLNG}/Polish			\
			${EGLNG}/Portuguese ${CFLNG}/Portuguese		\
			${EGLNG}/Romanian ${CFLNG}/Romanian		\
			${EGLNG}/Russian_koi8 ${CFLNG}/Russian_koi8	\
			${EGLNG}/Russian_windows1251			\
				${CFLNG}/Russian_windows1251		\
			${EGLNG}/Serbian ${CFLNG}/Serbian		\
			${EGLNG}/Spanish ${CFLNG}/Spanish		\
			${EGLNG}/Turkish ${CFLNG}/Turkish		\
			${EGLNG}/Ukrainian_windows1251			\
				${CFLNG}/Ukrainian_windows1251

post-extract:
			@${FIND} ${WRKSRC} -type d -exec ${CHMOD} +x {} \;
			@${RM} ${WRKSRC}/languages/.new

.include "../../mk/bsd.pkg.mk"
