# $NetBSD: Makefile,v 1.7 2020/08/31 18:12:49 wiz Exp $

DISTNAME=		HTML-CalendarMonthSimple-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-CalendarMonthSimple
COMMENT=		Perl Module for Generating HTML Calendars
LICENSE=		public-domain

DEPENDS+=		p5-Date-Calc>=0:../../devel/p5-Date-Calc

PERL5_PACKLIST=		auto/HTML/CalendarMonthSimple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
