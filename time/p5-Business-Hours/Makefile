# $NetBSD: Makefile,v 1.2 2017/06/05 14:25:01 ryoon Exp $

DISTNAME=	Business-Hours-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RU/RUZ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-Hours
COMMENT=	Calculate business hours in a time period
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Set-IntSpan>=1.12:../../devel/p5-Set-IntSpan

PERL5_PACKLIST=	auto/Business/Hours/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
