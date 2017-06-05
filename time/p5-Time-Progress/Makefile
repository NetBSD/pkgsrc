# $NetBSD: Makefile,v 1.17 2017/06/05 14:25:06 ryoon Exp $

DISTNAME=	Time-Progress-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Progress/
COMMENT=	Elapsed and estimated finish time reporting
LICENSE=	${PERL5_LICENSE} # see README

PERL5_PACKLIST=		auto/Time/Progress/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
