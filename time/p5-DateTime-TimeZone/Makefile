# $NetBSD: Makefile,v 1.25 2009/12/15 12:59:51 wiz Exp $

DISTNAME=	DateTime-TimeZone-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Module-Build>=0.35000:../../devel/p5-Module-Build

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/TimeZone/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
