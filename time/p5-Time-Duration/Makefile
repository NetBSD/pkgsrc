# $NetBSD: Makefile,v 1.14 2016/06/08 19:24:52 wiz Exp $

DISTNAME=      	Time-Duration-1.20
#PKGNAME=	p5-${DISTNAME}0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~avif/Time-Duration-1.04/Duration.pm
COMMENT=	Perl5 module for rounded or exact English expression of durations
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PERL5_PACKLIST=		auto/Time/Duration/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
