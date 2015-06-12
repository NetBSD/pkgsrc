# $NetBSD: Makefile,v 1.25 2015/06/12 10:51:44 wiz Exp $

DISTNAME=	DateTime-Locale-0.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Locale/
COMMENT=	Localization data for p5-DateTime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Dist-CheckConflicts-[0-9]*:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-Validate>=0.91:../../devel/p5-Params-Validate
DEPENDS+=	p5-Params-Validate>=0.91:../../devel/p5-Params-Validate

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
