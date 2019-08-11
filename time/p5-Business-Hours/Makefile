# $NetBSD: Makefile,v 1.6 2019/08/11 13:24:03 wiz Exp $

DISTNAME=	Business-Hours-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Business-Hours
COMMENT=	Calculate business hours in a time period
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Set-IntSpan>=1.12:../../devel/p5-Set-IntSpan

PERL5_PACKLIST=	auto/Business/Hours/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
