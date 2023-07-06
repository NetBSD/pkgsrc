# $NetBSD: Makefile,v 1.18 2023/07/06 09:42:20 wiz Exp $

DISTNAME=	Apache-LogFormat-Compiler-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Apache-LogFormat-Compiler
COMMENT=	Compile a log format string to perl-code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POSIX-strftime-Compiler>=0.30:../../time/p5-POSIX-strftime-Compiler

TOOL_DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-Try-Tiny>=0.12:../../devel/p5-Try-Tiny
TOOL_DEPENDS+=	p5-URI>=1.60:../../www/p5-URI
TOOL_DEPENDS+=	p5-Test-MockTime>=0:../../time/p5-Test-MockTime

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Apache/LogFormat/Compiler/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
