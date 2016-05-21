# $NetBSD: Makefile,v 1.14 2016/05/21 13:11:36 wen Exp $

DISTNAME=	Time-Progress-2.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Progress/
COMMENT=	Elapsed and estimated finish time reporting
LICENSE=	${PERL5_LICENSE} # see README

PERL5_PACKLIST=		auto/Time/Progress/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
