# $NetBSD: Makefile,v 1.5 2003/05/22 07:35:42 wiz Exp $
#

DISTNAME=		Time-HiRes-1.47
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5thr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@netbsd.org
HOMEPAGE=		http://search.cpan.org/author/JHI/Time-HiRes/
COMMENT=		perl5 module for high resolution time, sleep, and alarm

USE_BUILDLINK2=		YES

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

TEST_TARGET=		test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
