# $NetBSD: Makefile,v 1.1.1.1 1999/12/02 20:46:35 rh Exp $
#

DISTNAME=       HTML-Embperl-1.2.0
PKGNAME=        ap-Embperl-1.2.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl.apache.org/embperl/

DEPENDS+=	ap-perl-*:../../www/ap-perl
DEPENDS+=	p5-HTML-Parser-*:../../www/p5-HTML-Parser

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} \
		${MAKE_ENV} \
		APACHE_SRC=${PREFIX}/include/httpd \
		APACHE_MODULES=${PREFIX}/lib/httpd \
		APACHE=${PREFIX}/sbin/httpd \
		${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
