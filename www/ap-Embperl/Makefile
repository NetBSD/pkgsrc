# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:41 wiz Exp $
#

DISTNAME=       HTML-Embperl-1.2.0
PKGNAME=        ap-Embperl-1.2.0
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/} \
		ftp://ftp.dev.ecos.de/pub/perl/embperl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl.apache.org/embperl/
COMMENT=	Perl5 library for embedding perl in HTML documents

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=	auto/HTML/Embperl/.packlist

MAKE_ENV+=	APACHE_SRC=${PREFIX}/include/httpd
MAKE_ENV+=	APACHE_MODULES=${PREFIX}/lib/httpd
MAKE_ENV+=	APACHE=${PREFIX}/sbin/httpd

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
