# $NetBSD: Makefile,v 1.36 2011/08/14 15:28:47 obache Exp $

DISTNAME=	DateTime-TimeZone-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Build>=0.35000}:../../devel/p5-Module-Build

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate

# on HPUX it requires ../../time/p5-DateTime-TimeZone-HPUX
# but this will result in circular dependency

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/TimeZone/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
