# $NetBSD: Makefile,v 1.4 2005/02/23 18:32:35 wiz Exp $
#

DISTNAME=		Apache-Test-1.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Test/
COMMENT=		Wrapper for Test.pm to test an Apache server

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
