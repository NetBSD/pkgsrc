# $NetBSD: Makefile,v 1.5 1999/09/01 07:41:01 itojun Exp $
#
# The fourth number in the PKGNAME version indicates a NetBSD pkg revision
# (to indicate changes in the shipped third party patches such as the mod_ssl
# EAPI when there has been no change to the Apache version number).
#
# This package does not compile in mod_ssl support hooks, as it conflicts
# with IPv6 enable patch.
# IPv6 enable patch conflicts with third-party modules anyway, due to
# sanity fixes in apache module API (for example, avoid u_long for IPv4 addrs)
#

DISTNAME=		apache_1.3.9
PKGNAME=		apache6-1.3.9
CATEGORIES=		www
MASTER_SITES=		http://www.apache.org/dist/ \
			ftp://ftp.modssl.org/source/ \
			http://www.netbsd.org/images/logos/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sitedrivenby.gif
#			${SSL_DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		apache-139-v6-19990901a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.apache.org/

CONFLICTS=		apache-*modssl-* apache-*

SSL_DISTNAME=		mod_ssl-2.2.8-1.3.6

EXTRACT_ONLY=		${DISTFILES:N*.gif}
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX} --libexecdir=${PREFIX}/lib/httpd \
			--runtimedir=/var/run --datadir=${PREFIX}/share/httpd \
			--logfiledir=/var/log/httpd --sysconfdir=${PREFIX}/etc/httpd \
			--proxycachedir=/var/spool/httpd/proxy \
			--includedir=${PREFIX}/include/httpd \
			--sbindir=${PREFIX}/sbin \
			--enable-module=most \
			--enable-module=auth_db \
			--disable-module=auth_dbm \
			--with-perl=${PREFIX}/bin/perl
#			--enable-rule=EAPI --disable-module=ssl 
CONFIGURE_SCRIPT=	configure.v6
CONFIGURE_ENV+=		OPTIM="${OPTIM}"

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_INET6)
BROKEN=			"IPv6 only build"
.endif

.if defined(APACHE_SUEXEC) && ${APACHE_SUEXEC} == YES
CONFIGURE_ARGS+=	--enable-suexec --suexec-caller=www \
			--suexec-safepath='/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin'
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+=	--disable-rule=STATUS
OPTIM+=			-DBUFFERED_LOGS
CFLAGS+=		-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

PLIST_SRC=		${WRKDIR}/PLIST

BUILD_DEFS+=		APACHE_PERF_TUNING APACHE_SUEXEC USE_INET6

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

#post-extract:
#	@${CP} ${FILESDIR}/ap_include_extern.h ${WRKSRC}/src/include/
#	@${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.c ${WRKSRC}/src/ap/
#	@${CP} ${WRKDIR}/${SSL_DISTNAME}/pkg.eapi/*.h ${WRKSRC}/src/include/

#pre-patch:
#	@cd ${WRKSRC} && ${CAT} \
#		../${SSL_DISTNAME}/pkg.eapi/eapi.patch \
#		../${SSL_DISTNAME}/pkg.sslcfg/sslcfg.patch \
#		../${SSL_DISTNAME}/pkg.sslmod/sslmod.patch \
#		../${SSL_DISTNAME}/pkg.sslsup/sslsup.patch \
#		| ${PATCH} ${PATCH_ARGS}
#	@cd ${WRKSRC} && tail +129 \
#		../${SSL_DISTNAME}/pkg.ssldoc/ssldoc.patch \
#		| ${PATCH} ${PATCH_ARGS}

post-patch:
	@find ${WRKSRC}/htdocs -name '*.orig' | xargs ${RM}
	@${CHMOD} +x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/apache.sh \
	  >${WRKDIR}/apache.sh

post-install:
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif \
	  ${PREFIX}/share/httpd/htdocs
	${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh
	@${MV} ${PREFIX}/lib/httpd/libproxy.so \
	  ${PREFIX}/lib/httpd/mod_proxy.so 2>/dev/null || \
	  ${MKDIR} ${PREFIX}/lib/httpd
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.for FILE in man/man8/suexec.8 sbin/suexec
	@if [ -e ${PREFIX}/${FILE} ]; then \
	  ${ECHO} ${FILE} >>${PLIST_SRC}; \
	fi
.endfor

.include "../../mk/bsd.pkg.mk"

.if !defined(NOPIC)
CONFIGURE_ARGS+=	--enable-module=so --enable-shared=proxy
.else
CONFIGURE_ARGS+=	--disable-module=proxy
.endif
