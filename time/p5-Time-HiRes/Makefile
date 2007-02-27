# $NetBSD: Makefile,v 1.22 2007/02/27 13:12:28 wiz Exp $

DISTNAME=		Time-HiRes-1.9706
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
