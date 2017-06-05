# $NetBSD: Makefile,v 1.3 2017/06/05 14:25:17 ryoon Exp $

DISTNAME=		HTML-CalendarMonthSimple-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-CalendarMonthSimple
COMMENT=		Perl Module for Generating HTML Calendars
LICENSE=		public-domain

DEPENDS+=		p5-Date-Calc>=0:../../devel/p5-Date-Calc

PERL5_PACKLIST=		auto/HTML/CalendarMonthSimple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
