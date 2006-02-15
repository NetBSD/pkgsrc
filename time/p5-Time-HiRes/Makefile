# $NetBSD: Makefile,v 1.21 2006/02/15 22:53:59 abs Exp $

DISTNAME=		Time-HiRes-1.87
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5thr
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JH/JHI/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Time-HiRes/
COMMENT=		Perl5 module for high resolution time, sleep, and alarm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Time/HiRes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
