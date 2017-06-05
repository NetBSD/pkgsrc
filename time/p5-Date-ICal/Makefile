# $NetBSD: Makefile,v 1.11 2017/06/05 14:25:02 ryoon Exp $

DISTNAME=	Date-ICal-2.678
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Date-ICal/
COMMENT=	Perl extension for ICalendar date objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Leapyear>=1.03:../../time/p5-Date-Leapyear

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Date/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
