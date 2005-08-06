# $NetBSD: Makefile,v 1.7 2005/08/06 06:19:36 jlam Exp $
#

DISTNAME=		Apache-Test-1.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Test/
COMMENT=		Wrapper for Test.pm to test an Apache server

PERL5_PACKLIST=		auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
