# $NetBSD: Makefile,v 1.13 2019/08/11 13:24:06 wiz Exp $

DISTNAME=	DateTime-Format-DateManip-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DateTime::Format::DateManip
COMMENT=	Convert Date::Manip dates and durations to/from DateTimes

DEPENDS+=	p5-DateTime>0:../../time/p5-DateTime
DEPENDS+=	p5-Date-Manip>0:../../devel/p5-Date-Manip

PERL5_MODULE_TYPE=     Module::Build
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/DateManip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
