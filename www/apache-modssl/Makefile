# $NetBSD: Makefile,v 1.9 1998/11/12 23:59:17 frueauf Exp $
#

PKGNAME=	apache-modssl-1.3.2.2012
CATEGORIES=	www security
MASTER_SITES+=	http://www.engelschall.com/sw/mod_ssl/distrib/ \
		ftp://ftp.engelschall.com/sw/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/
DISTFILES+=	mod_ssl-2.0.12-1.3.2${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org

DEPENDS+=	SSLeay-0.9.0b:../../security/ssleay

CONFLICTS=	apache-1.3.1 apache-1.3.2 apache-modssl-1.3.2

EXTRACT_ONLY+=	mod_ssl-2.0.12-1.3.2${EXTRACT_SUFX}

RESTRICTED=	"Contains cryptography"

IS_INTERACTIVE=	yes

CONFIGURE_ARGS+=--enable-module=ssl
CONFIGURE_ENV+=	SSL_BASE=${PREFIX} SSL_CNFDIR=${PREFIX}/lib

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
CONFIGURE_ENV+=	RSA_BASE=${PREFIX}/lib
.endif

PLIST_SRC=	${PKGDIR}/PLIST ../apache/pkg/PLIST

.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
fetch-depends:
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  People with no RSA
	@${ECHO} license MUST set this variable to YES.  Users outside
	@${ECHO} the USA MUST set this variable to NO.  RSA licensees may
	@${ECHO} choose -- NO is faster.  This setting must match what the
	@${ECHO} SSLeay pkg was compiled with.
	@${FALSE}
.endif

pre-patch: pre-patch-modssl
pre-patch-modssl:
	@cd ${WRKDIR}/mod_ssl-2.0.12-1.3.2 \
		&& ${ECHO_MSG} "===>  Applying mod_ssl-2.0.12 extension" \
		&& ./configure --with-apache=../${DISTNAME}

certificate:
	@cd ${WRKSRC} \
		&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
		&& ${MAKE} certificate

# There's lots of tuning the user can do; this makes it common.
.include "../apache/Makefile"
