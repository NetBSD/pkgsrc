# $NetBSD: Makefile,v 1.1.1.1 2005/01/26 16:17:12 cube Exp $

DISTNAME=	DateTime-TimeZone-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
BUILD_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_BUILDLINK3=	YES

.include "../../time/p5-DateTime-Locale/plist.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
