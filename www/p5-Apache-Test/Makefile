# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 12:56:14 cube Exp $
#

DISTNAME=		Apache-Test-1.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://perl.apache.org/docs/1.0/api/Apache/test.html
COMMENT=		Wrapper for Test.pm to test an Apache server

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
