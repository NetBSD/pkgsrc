# $NetBSD: Makefile,v 1.14 2020/08/31 18:12:21 wiz Exp $

DISTNAME=	Date-Leapyear-1.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Date-Leapyear
COMMENT=	Is a particular year a leap year?
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Date/Leapyear/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
