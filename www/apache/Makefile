# $NetBSD: Makefile,v 1.25 1998/12/03 17:23:52 tv Exp $
#
# The fourth number in the PKGNAME version indicates a NetBSD pkg revision
# (to indicate changes in the shipped third party patches such as the mod_ssl
# EAPI when there has been no change to the Apache version number).
#
# This pkg does not compile in mod_ssl, only the `mod_ssl EAPI' (a set of
# code hooks that allow mod_ssl to be compiled separately later, if desired).
#

DISTNAME=		apache_1.3.3
PKGNAME=		apache-1.3.3.0
CATEGORIES=		www
MASTER_SITES=		http://www.apache.org/dist/ \
			http://www.engelschall.com/sw/mod_ssl/distrib/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${SSL_DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif

MAINTAINER=		cjs@netbsd.org
HOMEPAGE=		http://www.apache.org/

CONFLICTS=		apache-1.3.[012] apache-*modssl-*

SSL_DISTNAME=		mod_ssl-2.1.2-1.3.3

EXTRACT_ONLY=		${DISTFILES:N*.gif}
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX} --libexecdir=${PREFIX}/lib/httpd \
			--runtimedir=/var/run --datadir=${PREFIX}/share/httpd \
			--logfiledir=/var/log/httpd --sysconfdir=${PREFIX}/etc/httpd \
			--proxycachedir=/var/spool/httpd/proxy \
			--includedir=${PREFIX}/include/httpd \
			--enable-rule=EAPI --enable-module=most \
			--disable-module=ssl --enable-module=auth_db \
			--disable-module=auth_dbm \
			--with-perl=${PREFIX}/bin/perl
CONFIGURE_ENV+=		OPTIM="${OPTIM}"

.if defined(APACHE_SUEXEC)
CONFIGURE_ARGS+=	--enable-suexec --suexec-caller=www \
			--suexec-userdir=WWW \
			--suexec-safepath='/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin'
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+=	--disable-rule=STATUS
OPTIM+=			-DBUFFERED_LOGS
CFLAGS+=		-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

post-extract:
	@${CP} ${FILESDIR}/ap_include_extern.h ${WRKSRC}/src/include/
	@${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.c ${WRKSRC}/src/ap/
	@${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.h ${WRKSRC}/src/include/

pre-patch:
	@cd ${WRKSRC} && ${CAT} \
		../${SSL_DISTNAME}/pkg.eapi/eapi.patch \
		../${SSL_DISTNAME}/pkg.sslcfg/sslcfg.patch \
		../${SSL_DISTNAME}/pkg.sslmod/sslmod.patch \
		../${SSL_DISTNAME}/pkg.sslsup/sslsup.patch \
		| ${PATCH} ${PATCH_ARGS}
post-patch:
	@cd ${WRKSRC}/src/include && \
		${SED} -e s,@@PREFIX@@,${PREFIX}, ap_config.h >tmp && \
		${MV} -f tmp ap_config.h
	@find ${WRKSRC}/htdocs -name '*.orig' | xargs ${RM}

post-install:
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/httpd/htdocs
	${INSTALL_DATA_DIR} ${PREFIX}/lib/httpd

.include "../../mk/bsd.pkg.mk"

.if !defined(NOPIC)
CONFIGURE_ARGS+=	--enable-module=so
.endif
