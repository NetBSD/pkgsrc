# $NetBSD: Makefile,v 1.1 2014/11/03 02:12:25 wen Exp $

DISTNAME=	Test-Time-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~satoh/Test-Time/
COMMENT=	Override time()/sleep() core functions for testing
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Test/Time/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
