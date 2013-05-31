# $NetBSD: Makefile,v 1.2 2013/05/31 12:42:34 wiz Exp $
#

DISTNAME=	Apache-LogFormat-Compiler-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-LogFormat-Compiler/
COMMENT=	Compile a log format string to perl-code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PathTools-[0-9]*:../../devel/p5-PathTools
DEPENDS+=	p5-CPAN-Meta-[0-9]*:../../devel/p5-CPAN-Meta

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Apache/LogFormat/Compiler/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
