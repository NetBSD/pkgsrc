# FreeBSD: Makefile,v 1.2 1998/08/29 21:24:13 rse Exp
# $NetBSD: Makefile,v 1.1.1.1 1998/09/04 23:37:23 explorer Exp $
#

DISTNAME=	apache_1.3.1
PKGNAME=	apache-modssl-1.3.1
CATEGORIES=	www security
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.engelschall.com/sw/mod_ssl/distrib/ \
		ftp://ftp.engelschall.com/sw/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mod_ssl-2.0.6-1.3.1${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.apache.org/

BUILD_DEPENDS=	ssleay:../../security/ssleay \
		${PREFIX}/lib/libssl.a:../../security/ssleay \
		${PREFIX}/lib/libcrypto.a:../../security/ssleay
RUN_DEPENDS=	ssleay:../../security/ssleay
CONFLICTS=	apache-1.3.1

RESTRICTED=	"Contains cryptography"

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--compat --prefix=${PREFIX}/http --exec-prefix=${PREFIX} \
		--mandir=${PREFIX}/man --libexecdir=${PREFIX}/libexec/apache \
		--sbindir=${PREFIX}/sbin --runtimedir=/var/run \
		--enable-module=most --enable-module=auth_db \
		--disable-module=auth_dbm --with-perl=${PREFIX}/bin/perl \
		--enable-module=ssl

.if defined(APACHE_SUEXEC)
CONFIGURE_ARGS+=--enable-suexec --suexec-caller=www \
		--suexec-userdir=WWW \
		--suexec-safepath='${PREFIX}/bin:/usr/local/bin:/usr/bin:/bin'
.endif

OPTIM=	-DHARD_SERVER_LIMIT=512 \
	-DDOCUMENT_LOCATION=\\"${PREFIX}/http/htdocs/\\" \
	-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+= --disable-rule=STATUS
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

.if !defined(NOPIC)
CONFIGURE_ARGS+=--enable-module=so --enable-shared=include
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' SSL_BASE=${PREFIX} \
	SSL_CNFDIR=${PREFIX}/etc RSA_BASE=${PREFIX}/lib

INSTALL_TARGET=	install-quiet

MAN1=	ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

pre-patch:
	@cd ${WRKDIR}/mod_ssl-2.0.6-1.3.1 \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-2.0.6 extension" \
	&& ./configure --with-apache=../${DISTNAME}

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} Installing ${PREFIX}/etc/rc.d/apache.sh ; \
		${CP} ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh ; \
	fi

.include "../../mk/bsd.pkg.mk"
