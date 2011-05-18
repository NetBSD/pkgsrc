# $NetBSD: Makefile,v 1.1.1.1 2011/05/18 01:27:43 dmcmahill Exp $

DISTNAME=	Date-Leapyear-1.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RB/RBOW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rbow/Date-Leapyear-1.72/
COMMENT=	Is a particular year a leap year?
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Date/Leapyear/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
