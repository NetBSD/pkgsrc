# $NetBSD: Makefile,v 1.14 2016/01/30 13:06:09 mef Exp $

DISTNAME=	DateTime-Format-Builder-0.81
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/DateTime-Format-Builder/
COMMENT=	Create DateTime parser classes and objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Factory-Util>=1.6:../../devel/p5-Class-Factory-Util
DEPENDS+=	p5-DateTime>=1.00:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime>=1.04:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
# for make test
BUILD_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/Format/Builder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
