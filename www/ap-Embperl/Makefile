# $NetBSD: Makefile,v 1.2 2000/08/27 10:37:03 jlam Exp $
#

DISTNAME=       HTML-Embperl-1.2.0
PKGNAME=        ap-Embperl-1.2.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl.apache.org/embperl/

DEPENDS+=	ap-perl-*:../../www/ap-perl
DEPENDS+=	p5-HTML-Parser-*:../../www/p5-HTML-Parser

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTML/Embperl/.packlist

MAKE_ENV+=	APACHE_SRC=${PREFIX}/include/httpd
MAKE_ENV+=	APACHE_MODULES=${PREFIX}/lib/httpd
MAKE_ENV+=	APACHE=${PREFIX}/sbin/httpd

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
