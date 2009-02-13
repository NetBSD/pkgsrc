# $NetBSD: Makefile,v 1.1.1.1 2009/02/13 23:46:51 abs Exp $

DISTNAME=	Date-Calc-5.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Date::Calc
COMMENT=	Gregorian calendar date calculations

DEPENDS+=	p5-Bit-Vector>=6.4:../../devel/p5-Bit-Vector

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/Date/Calc/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
