# $NetBSD: Makefile,v 1.23 1998/10/05 14:26:01 tv Exp $
#
# The apache-modssl pkg .include's us, so that pkg tuning rules work for
# both without a major duplication of Makefiles.  So we use ?= and += in
# many of the constructs up here at top.
#

DISTNAME=	apache_1.3.2
PKGNAME?=	apache-1.3.2
CATEGORIES?=	www
MASTER_SITES+=	http://www.apache.org/dist/ \
		http://www.netbsd.org/images/logos/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.apache.org/

EXTRACT_ONLY+=	${DISTNAME}${EXTRACT_SUFX}
CONFLICTS?=	apache-1.3.0 apache-1.3.1 apache-modssl-1.3.1 apache-modssl-1.3.2.2012
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--compat --prefix=${PREFIX}/http --exec-prefix=${PREFIX} \
		--mandir=${PREFIX}/man --libexecdir=${PREFIX}/lib/apache \
		--sbindir=${PREFIX}/sbin --runtimedir=/var/run \
		--enable-module=most --enable-module=auth_db \
		--disable-module=auth_dbm --with-perl=${PREFIX}/bin/perl
CONFIGURE_ENV+=	OPTIM='${OPTIM}'
OPTIM=		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin\\"

.if defined(APACHE_SUEXEC)
CONFIGURE_ARGS+=--enable-suexec --suexec-caller=www \
		--suexec-userdir=WWW \
		--suexec-safepath='${PREFIX}/bin:/usr/local/bin:/usr/bin:/bin'
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+=--disable-rule=STATUS
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

post-patch:
	@find ${WRKSRC}/htdocs -name '*.orig' | xargs ${RM}

post-install:
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/http/htdocs

.include "../../mk/bsd.pkg.mk"

# Define some modules that are often replaced as shared modules that can be
# changed at runtime.  This allows an apxs-compiled .so to be "dropped in"
# without even changing httpd.conf.
# Only those defined here should be in PLIST-mi.shared.

.if !defined(NOPIC)
CONFIGURE_ARGS+=--enable-module=so --enable-shared=include
.endif

.if (${SHLIB_TYPE} == "ELF")
CONFIGURE_ENV+=	LDFLAGS_SHLIB_EXPORT=-Wl,--export-dynamic
.endif
