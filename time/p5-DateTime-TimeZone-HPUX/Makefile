# $NetBSD: Makefile,v 1.3 2011/08/14 15:28:47 obache Exp $

DISTNAME=	DateTime-TimeZone-HPUX-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone-HPUX/
COMMENT=	Handles timezones defined at the operating system level on HP-UX
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Build>=0.35000}:../../devel/p5-Module-Build

DEPENDS+=	p5-DateTime-TimeZone>=1.05:../../time/p5-DateTime-TimeZone

ONLY_FOR_PLATFORM=	HPUX-*-*

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/TimeZone/HPUX/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
