# $NetBSD: Makefile,v 1.42 2015/06/12 10:51:45 wiz Exp $

DISTNAME=		Time-HiRes-1.9726
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Time-HiRes/
COMMENT=		Perl5 module for high resolution time, sleep, and alarm
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Time/HiRes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
