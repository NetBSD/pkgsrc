# $NetBSD: Makefile,v 1.3 2013/06/29 09:29:05 sno Exp $
#

DISTNAME=	Apache-LogFormat-Compiler-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-LogFormat-Compiler/
COMMENT=	Compile a log format string to perl-code
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Try-Tiny>=0.12:../../devel/p5-Try-Tiny
BUILD_DEPENDS+=	p5-URI>=1.60:../../www/p5-URI

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Apache/LogFormat/Compiler/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
