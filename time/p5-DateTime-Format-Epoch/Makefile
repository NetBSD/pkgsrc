# $NetBSD: Makefile,v 1.22 2022/06/28 11:36:54 wiz Exp $

DISTNAME=	DateTime-Format-Epoch-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
#HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Epoch/
COMMENT=	Convert DateTimes to/from epoch seconds
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.31:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/Format/Epoch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
