# $NetBSD: Makefile,v 1.13 2007/12/31 06:53:17 obache Exp $

DISTNAME=		sarg-2.1
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sarg/}

PATCH_SITES=		http://sarg.sourceforge.net/
PATCHFILES=		datafile.patch lastlog.patch

MAINTAINER=		mishka@terabyte.com.ua
HOMEPAGE=		http://sarg.sourceforge.net/sarg.php
COMMENT=		Squid-Cache proxy server Analysis Report Generator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gcc					\
			--enable-bindir=${PREFIX}/bin			\
			--enable-mandir=${PREFIX}/${PKGMANDIR}/man1	\
			--enable-sysconfdir=${PKG_SYSCONFDIR:Q}

DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

DIST_SUBDIR=		${DISTNAME}
PKG_SYSCONFSUBDIR=	sarg
EGDIR=			${PREFIX}/share/examples/sarg
EGLNG=			${EGDIR}/languages
CFLNG=			${PKG_SYSCONFDIR}/languages

.include "../../mk/bsd.prefs.mk"

SQUID_ACCESSLOG?=	${VARBASE}/squid/logs/access.log
SARG_REPORTSDIR?=	${VARBASE}/sarg

OWN_DIRS+=		${SARG_REPORTSDIR} ${CFLNG}

SUBST_CLASSES+=		sargconf
SUBST_MESSAGE.sargconf=	Adjusting values in SARG configuration files.
SUBST_STAGE.sargconf=	post-configure
SUBST_FILES.sargconf=	sarg.conf sarg.1
SUBST_SED.sargconf=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.sargconf+=	-e 's,@SQUID_ACCESSLOG@,${SQUID_ACCESSLOG},g'
SUBST_SED.sargconf+=	-e 's,@SARG_REPORTSDIR@,${SARG_REPORTSDIR},g'

SUBST_CLASSES+=		gsort
SUBST_MESSAGE.gsort=	Adjusting sort to use GNU coreutils
SUBST_STAGE.gsort=	post-patch
SUBST_FILES.gsort=	authfail.c dansguardian_log.c email.c grepday.c \
	html.c index.c lastlog.c log.c realtime.c siteuser.c \
	smartfilter.c sort.c squidguard_log.c topsites.c topuser.c \
	totday.c useragent.c
SUBST_SED.gsort=	-e 's,"sort ,"'"${PREFIX}/bin/${GNU_PROGRAM_PREFIX}sort ,"

BUILD_DEFS+=		SQUID_ACCESSLOG SARG_REPORTSDIR
MAKE_ENV+=		PKG_FLAGS="-DSQUID_ACCESSLOG='\"${SQUID_ACCESSLOG}\"' \
			-DSARG_REPORTSDIR='\"${SARG_REPORTSDIR}\"'"	\
			EGDIR=${EGDIR:Q}

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
			${EGLNG}/Greek ${CFLNG}/Greek			\
			${EGLNG}/Hungarian ${CFLNG}/Hungarian		\
			${EGLNG}/Indonesian ${CFLNG}/Indonesian		\
			${EGLNG}/Italian ${CFLNG}/Italian		\
			${EGLNG}/Japanese ${CFLNG}/Japanese		\
			${EGLNG}/Latvian ${CFLNG}/Latvian		\
			${EGLNG}/Polish ${CFLNG}/Polish			\
			${EGLNG}/Portuguese ${CFLNG}/Portuguese		\
			${EGLNG}/Romanian ${CFLNG}/Romanian		\
			${EGLNG}/Russian_koi8 ${CFLNG}/Russian_koi8	\
			${EGLNG}/Russian_UTF-8 ${CFLNG}/Russian_UTF-8	\
			${EGLNG}/Russian_windows1251			\
				${CFLNG}/Russian_windows1251		\
			${EGLNG}/Serbian ${CFLNG}/Serbian		\
			${EGLNG}/Slovak ${CFLNG}/Slovak			\
			${EGLNG}/Spanish ${CFLNG}/Spanish		\
			${EGLNG}/Turkish ${CFLNG}/Turkish		\
			${EGLNG}/Ukrainian_windows1251			\
				${CFLNG}/Ukrainian_windows1251

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} +x {} \;
	${RM} ${WRKSRC}/languages/.new

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
