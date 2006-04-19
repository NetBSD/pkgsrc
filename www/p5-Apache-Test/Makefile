# $NetBSD: Makefile,v 1.9 2006/04/19 17:17:24 cube Exp $
#

DISTNAME=		Apache-Test-1.28
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Test/
COMMENT=		Wrapper for Test.pm to test an Apache server

CONFLICTS+=		ap2-perl-[0-9]*

PERL5_PACKLIST=		auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
