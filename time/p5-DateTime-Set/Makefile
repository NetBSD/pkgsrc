# $NetBSD: Makefile,v 1.21 2016/06/08 19:24:50 wiz Exp $

DISTNAME=	DateTime-Set-0.3600
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Set/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.12:../../time/p5-DateTime
DEPENDS+=	p5-Set-Infinite>=0.59:../../math/p5-Set-Infinite

PERL5_PACKLIST=	auto/DateTime/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
