# $NetBSD: Makefile,v 1.3 2011/08/14 15:28:44 obache Exp $

DISTNAME=	Date-ICal-1.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Date-ICal/
COMMENT=	Perl extension for ICalendar date objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Leapyear>=1.03:../../time/p5-Date-Leapyear

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Date/ICal/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
