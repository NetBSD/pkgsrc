# $NetBSD: Makefile,v 1.12 2011/08/14 15:28:46 obache Exp $

DISTNAME=	DateTime-Format-Natural-0.89
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Natural/
COMMENT=	Create machine readable date/time with natural parsing logic
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate
DEPENDS+=	p5-boolean-[0-9]*:../../devel/p5-boolean

BUILD_DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime

# recommended
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

PERL5_MODULE_TYPE=  	Module::Build
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Natural/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
