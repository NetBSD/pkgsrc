# $NetBSD: Makefile,v 1.2 2015/06/12 10:52:14 wiz Exp $

DISTNAME=	WWW-Mechanize-Cached-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~oalders/WWW-Mechanize-Cached/
COMMENT=	Cache response to be polite
LICENSE=	${PERL5_LICENSE}	

DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
BUILD_DEPENDS+= p5-Class-Load-[0-9]*:../../devel/p5-Class-Load
BUILD_DEPENDS+= p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+= p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
BUILD_DEPENDS+= p5-Find-Lib-[0-9]*:../../devel/p5-Find-Lib
BUILD_DEPENDS+= p5-CHI-[0-9]*:../../devel/p5-CHI

BUILD_DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/WWW/Mechanize/Cached/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
