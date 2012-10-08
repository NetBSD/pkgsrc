# $NetBSD: Makefile,v 1.36 2012/10/08 13:04:26 asau Exp $

DISTNAME=		Time-HiRes-1.9725
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5thr
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Time-HiRes/
COMMENT=		Perl5 module for high resolution time, sleep, and alarm
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Time/HiRes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
