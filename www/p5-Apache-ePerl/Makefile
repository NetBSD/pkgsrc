# $NetBSD: Makefile,v 1.1.1.1 1998/12/05 16:26:22 tv Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/

DEPENDS=		eperl-2.2.14:../../textproc/eperl
BUILD_DEPENDS=		${PREFIX}/lib/httpd/mod_perl.so:../../www/ap-perl
RUN_DEPENDS:=		${BUILD_DEPENDS}

WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
