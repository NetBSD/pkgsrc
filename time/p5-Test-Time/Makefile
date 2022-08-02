# $NetBSD: Makefile,v 1.16 2022/08/02 09:11:51 ast Exp $

DISTNAME=	Test-Time-0.092
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Time
COMMENT=	Override time()/sleep() core functions for testing
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=	auto/Test/Time/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
