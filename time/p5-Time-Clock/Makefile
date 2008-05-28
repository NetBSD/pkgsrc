# $NetBSD: Makefile,v 1.2 2008/05/28 21:06:34 abs Exp $

DISTNAME=	Time-Clock-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Clock/
COMMENT=	Twenty-four hour clock object with nanosecond precision

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Time/Clock/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
